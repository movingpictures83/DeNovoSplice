#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "DeNovoSplicePlugin.h"

void DeNovoSplicePlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
}

void DeNovoSplicePlugin::run() {}

void DeNovoSplicePlugin::output(std::string file) {
 std::string outputfile = file;
 //olego -v -r $Model -j $Junction_db -o r1.sam $Index $Forward_fastq
myCommand += "olego";
myCommand += " -v ";
myCommand += " -r ";
myCommand += PluginManager::addPrefix(myParameters["model"]);
myCommand += " -j ";
myCommand += PluginManager::addPrefix(myParameters["junction"]);
myCommand += " -o " + outputfile + " ";
myCommand += PluginManager::addPrefix(myParameters["index"]);
myCommand += " ";
myCommand += PluginManager::addPrefix(myParameters["fastq"]);
 system(myCommand.c_str());
}

PluginProxy<DeNovoSplicePlugin> DeNovoSplicePluginProxy = PluginProxy<DeNovoSplicePlugin>("DeNovoSplice", PluginManager::getInstance());
