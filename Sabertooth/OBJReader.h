#pragma once
#include <map>

class OBJReader
{
public:
	OBJReader();

	~OBJReader();

	enum ObjTypes {
		NONE,
		V,
		VN,
		VT,
		F,
		G,
		MTLLIB,
		USEMTL,
		COMMENTARY,
	};

	typedef std::map<std::string, ObjTypes> TypesMap;

	static TypesMap typesMap;

};

