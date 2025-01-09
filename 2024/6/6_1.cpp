#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>



int main()
{
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
    // for (const auto& line : lines) {
    //     std::cout << line << std::endl;
    // }

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
    std::vector<std::pair<int, int>> dirs = {{0,-1},{1,0},{0,1},{-1,0} };

    int dir = 0;

    std::set<std::pair<int,int>> vis;
    while (true)
    {
        int xp = x+dirs[dir].first;
        int yp = y+dirs[dir].second;

        if (!isInRange(xp,yp))
            break;

        if(lines[yp][xp] == '#')
        {
            dir = (dir +1) %4;
        }
        else{
            x = xp; y = yp;
            lines[yp][xp] = 'X';
       vis.insert(std::pair(xp,yp));
        }

    }


    // for (auto vi : vis){
    //     std::cout<<vi.first<<" "<<vi.second<<std::endl;
    // }

    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }

    std::cout << "count : " <<vis.size()<<std::endl;
    return 0;
}




