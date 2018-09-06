#include "OBJReader.h"
#include "Mesh.h"
#include <fstream>
#include <sstream>


OBJReader::OBJReader()
{
}


OBJReader::~OBJReader()
{
}

Mesh *read(string filename) {
	Mesh *mesh = new Mesh;
	ifstream arq(filename);

	while (!arq.eof()) {
		string line;
		getline(arq, line);
		stringstream sline;
		sline << line; string temp; sline >> temp;
		if (temp == "v") {
			// ler v�rtice ... 
			float x, y, z;
			sline >> x >> y >> z;
			// ... atribuir v�rtices da malha // 
		}
		else if (temp == "f") {
			// implementar l�gica de vari��es 
			// para face: v, v/t/n, v/t e v//n 
			string token;
			sline >> token;
			// v/t/n, por exemplo 
			stringstream stoken;
			string aux;
			getline(stoken, aux, '/'); //
		}
		else {
			// else-if 
		    // Verificar outras possibilidades: // g, vn, } 
			return mesh;
		}
	}
}
