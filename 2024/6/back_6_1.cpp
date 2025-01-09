#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>



int main()
{
    std::cout<<"hello !!"<<std::endl;



    // std::string filename("sample.txt");
    std::string filename("data");
    std::ifstream input(filename);

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input,line))
        lines.push_back(line);

    input.close();

    int X = lines[0].size();
    int Y = lines.size();
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }

    std::cout<<" X= "<<X<<"  Y= "<<Y<<std::endl;
    auto isInRange  =  [&](const int x, const int y) -> bool {
        if ( 0 <= x && x < X && 0<= y && y < Y )
            return true;

        return false;
    };



    char target = '^';
    int x = -1, y = -1; // Default coordinates if not found

    for (size_t row = 0; row < lines.size(); ++row) {
        size_t col = lines[row].find(target); // Find the character in the row
        if (col != std::string::npos) {       // If found
            x = static_cast<int>(col);        // Set x to the column index
            y = static_cast<int>(row);        // Set y to the row index
            break;                            // Stop searching
        }
    }

    std::cout<<"location : " <<x<<y<<std::endl;

    std::vector<std::pair<int, int>> direction = {{0,-1},{1,0},{0,1},{-1,0} };
    int size = 4;
    int dir_index = 0;


    y = y -1;

    int dir_i = 0;

    int dx = direction[dir_i].first;
    int dy = direction[dir_i].second;
    int i = 0;
    for ( ; isInRange(x,y) ; i++)
    {

        std::cout<<" ["<<x<<" , "<<y<<" ] = "<<lines[y][x]<<std::endl;

        lines[y][x] = 'X';
        std::cout<<" ["<<x<<" , "<<y<<" ] = "<<lines[y][x]<<std::endl;

        while(isInRange(x+dx,y+dy)&&lines[y+dy][x+dx] == '#')
        
        {
            dir_i = (dir_i + 1 ) %size;

            dx = direction[dir_i].first;
            dy = direction[dir_i].second;
        }

        x = x+dx;
        y = y+dy;
    }

    std::cout<<"printing ..."<<std::endl;
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }


    int count = 0;
    for (auto & line : lines)
    {
        count += std::count(line.begin(), line.end(), 'X');


    }


    std::cout << "count : " <<count<<std::endl;



    return 0;
}




