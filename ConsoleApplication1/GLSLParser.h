#ifndef GLSL_PARSER_H
#define GLSL_PARSER_H

#include "ShaderBase.h"

#include <string>
#include <vector>


struct GLSL_Var_{
	hyperspace::shader::semantic_	sem;
	hyperspace::shader::datatype_	type;
	hyperspace::shader::stage_		stage;
	std::string						name;
};

class GLSL_Parser{
public:
	GLSL_Parser(std::string Path_);
	~GLSL_Parser();

	void Parse();

	std::vector<GLSL_Var_>	attributes;
	std::vector<GLSL_Var_>	varying;
	std::vector<GLSL_Var_>	uniforms;

private:

	void Process(std::string &b);
	void ProcessToken(std::size_t &pos, std::vector<std::string> &v);
	void DetermineSemantic(GLSL_Var_ &var, std::string &str);
	void DetermineType(GLSL_Var_ &var, std::string &str);
	std::string					buffer_vertex;
	std::string					buffer_fragment;
	hyperspace::shader::stage_  current_stage;
	
};



#endif
