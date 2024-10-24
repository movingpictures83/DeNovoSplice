#ifndef DENOVOSPLICEPLUGIN_H
#define DENOVOSPLICEPLUGIN_H

#include "Plugin.h"
#include "Tool.h"
#include "PluginProxy.h"
#include <string>

class DeNovoSplicePlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "DeNovoSplice";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
