#include <iostream>
#include <bitset>
#include <math.h>
#include <vector>
#include <fstream>
#include <set>
#include <map>
#include <sstream>

int main()
{
    std::string filename("test");
    // std::string filename("data");
    // std::string filename("sample");
    std::ifstream input(filename);

    std::vector<std::string> lines;
    std::string line;


    std::map<long long,std::vector<int>> look;

    while (std::getline(input,line))
    {
        std::stringstream ln(line);
        std::string sum;

        std::getline(ln , sum , ':');

        std::vector<int> decimal;
        std::string value;
        

        
        while (ln >> value) { 
            decimal.push_back(std::stoi(value));
        }
       
        std::cout<<std::endl;

        look[std::stoll(sum)] = decimal;


    }


    // std::cout<<"total size : " <<look.size()<<std::endl;






    long long result = 0;
    for (auto line : look)
    {
        auto check = line.first;
        std::vector <int> vals = line.second;


        long long line_result;
        int size = vals.size() ;
        for (int i = 0 ; i < pow(2,size) ; i++ )
        {
            line_result = vals[0];
            for (int j = 1 ; j < size ; j++ )
            {
                if(i & (1 << j))
                    line_result += vals[j] ;

                else
                    line_result *= vals[j] ;
            }
            // std::cout<<std::endl;

            if (line_result == check)
            {

                std::cout<<check<<" : ";
                std::cout<<vals[0];
                for (int j = 1 ; j < size ; j++ )
                {
                    if(i & (1 << j))
                        std::cout<<" + "<<vals[j];

                    else
                        std::cout<<" * "<<vals[j];
                }
                std::cout<<std::endl;



                result += line_result;
                break;
            }
        }

        // std::cout<<std::endl;

    }
    std::cout<<" result 1 : "<<result<<std::endl;
    return 0;
}


