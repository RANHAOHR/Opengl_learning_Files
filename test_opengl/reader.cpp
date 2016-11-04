//reader.cpp

#include <GL/freeglut.h>
#include <fstream>

#include "reader.h"
#include <iostream>
using namespace std;

Reader::Reader()
{
    for(int i = 0; i < 256; i++ ) {
        vertex[i].x = 0;
        vertex[i].y = 0;
        vertex[i].z = 0;
    }
}

Reader::~Reader()
{

}

void Reader::load(char* filename)
{
    ifstream file;
    file.open(filename);

    
    if( file == NULL ){
        cout<<"Impossible to open the file !"<<endl;
        return ;
    }

    while( 1 ){
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        

        //vertex
        if ( strcmp( lineHeader, "v" ) == 0 ){
        glm::vec3 vertex;
        fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
        temp_vertices.push_back(vertex);
        }
        /////// vertex texture
        else if ( strcmp( lineHeader, "vt" ) == 0 ){
        glm::vec2 uv;
        fscanf(file, "%f %f\n", &uv.x, &uv.y );
        temp_uvs.push_back(uv);
        }
        ///vertex normal
        else if ( strcmp( lineHeader, "vn" ) == 0 ){
        glm::vec3 normal;
        fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
        temp_normals.push_back(normal);
        }
        else if ( strcmp( lineHeader, "f" ) == 0 ){
        std::string vertex1, vertex2, vertex3;
        unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
        int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
        if (matches != 9){
            cout<<"File can't be read by our simple parser : ( Try exporting with other options"<<endl;
            return ;
        }
        vertexIndices.push_back(vertexIndex[0]);
        vertexIndices.push_back(vertexIndex[1]);
        vertexIndices.push_back(vertexIndex[2]);
        uvIndices    .push_back(uvIndex[0]);
        uvIndices    .push_back(uvIndex[1]);
        uvIndices    .push_back(uvIndex[2]);
        normalIndices.push_back(normalIndex[0]);
        normalIndices.push_back(normalIndex[1]);
        normalIndices.push_back(normalIndex[2]);
        }

        for( unsigned int i=0; i<vertexIndices.size(); i++ ){
            unsigned int vertexIndex = vertexIndices[i];
            glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
            out_vertices.push_back(vertex);

        }


    }

    // string str;

    // while(!file.eof()) //while we are still in the file
    // {
    //     getline(file,str); //move one line down
    //     if(str[0] == 'v') break; //if we have a vertex line, stop
    // }

    // int v = 0;
    // int counter = 0;
    // while(str[0] == 'v') {
    //     cout<<"flag 1"<<endl;
    //     int i = 0;

    //     while(true)
    //     {
    //         cout<<"flag 2"<<endl;
    //         while(str[i] == ' ' )
    //         {
    //             i++; //move a space over
    //         }
    //         i++;
    //         i++;
    //         int j = i, k = i;
    //         while(str[i] != ' ') {  
    //             i++;
    //             k = i;
    //         }
    //         cout<<"flag 3"<<endl;
    //         vertex[v].x = atof(str.substr(j, k-j).c_str());

    //         //moving on to the y coord
    //         cout<<"flag 4"<<endl;
    //         while(str[i] == ' ' ) {
    //             i++;
    //         }
    //         cout<<"flag 5"<<endl;
    //         int q = i, w = i;
    //         while(str[i] != ' ' ) {
    //             i++;
    //             w = i;
    //         }
    //         vertex[v].y = atof(str.substr(q, w-q).c_str());
    //         cout<<"flag 6"<<endl;
    //         while(str[i] == ' ' ) {
    //             i++;
    //         }
    //         cout<<"flag 7"<<endl;
    //         int a = i, s = i;
    //         while(str[i] != ' ' ) {
    //             i++;
    //             s = i;
    //         }
    //         vertex[v].z = atof(str.substr(a, s-a).c_str());
    //         cout<<"flag 8"<<endl;

    //         break;
    //         counter++;
    //         cout<<"the "<< counter << "round"<<endl;
    //     }
    //     v++; 
    //     getline(file, str);  
    // }
    // cout<<"end readfile"<<endl;
}

void Reader::draw(char *filename)
{
    ifstream file;
    file.open(filename);

    string str;

    while(true)
    {
        getline(file, str);
        if(str[0] == 'f' ) {
            break;
        }
    }

    int i = 0;

    while(str[0] == 'f')
    {

        while(str[i] == 'f') i++;
        while(str[i] == ' ') i++;
        int j = i, k = i;

        while(str[i] != ' ') {  
            i++;
            k = i;
        }

        int one = atof(str.substr(j, k - j).c_str());

        i +=1;

        j = i;
        k = i;

        while(str[i] != ' ') { 
            i++;
            k = i;
        }

        int two = atof(str.substr(j, k - j).c_str());

        i+=1;

        j = i;
        k = i;

        while(str[i] != ' ') {  
            i++;
            k = i;
        }

        int three = atof(str.substr(j, k - j).c_str());

        i+=1;

        j = i;
        k = i;

        while(str[i] != ' ') {  
            i++;
            k = i;
        }

        int four = atof(str.substr(j, k - j).c_str());

        glBegin(GL_POLYGON);
        glVertex3d(vertex[one - 1].x, vertex[one - 1].y, vertex[one - 1].z);
        glVertex3d(vertex[two - 1].x, vertex[two - 1].y, vertex[two - 1].z);
        glVertex3d(vertex[three - 1].x, vertex[three - 1].y, vertex[three - 1].z);
        glVertex3d(vertex[four - 1].x, vertex[four - 1].y, vertex[four - 1].z);
        glEnd();

        getline(file, str);
        i = 0;
    }

}
