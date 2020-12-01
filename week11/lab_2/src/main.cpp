// HTMLParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

vector<string> GetDataFile(string url);					// Function to read input file
vector<string> ParseData(vector<string> s, string pattern);		// Utility function to perform parsing
bool WriteExtractNews(vector<string>& news, vector<string>& urls);	// Function to write output file

int main()
{
    std::vector<std::string> vDoc = GetDataFile("sourceNews.html");
    std::vector<std::string> vHref = ParseData(vDoc, "^<a href=.+true\">.+</a>");
    std::vector<std::string> vUrls = ParseData(vHref, "https://.+?\"");
    std::vector<std::string> vNews = ParseData(vHref, "\"true\">.+</a>");

    if(WriteExtractNews(vNews, vUrls)) {
        std::cout << "News Extraction COMPLETED";
    }

	return 0;
}

vector<string> GetDataFile(string url) {
    ifstream inFile{url};

    if(!inFile) {
        std::cerr << "File not Found\n";
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> strHTML;
    std::string strTmp{""};

    while(std::getline(inFile, strTmp)) {
        strHTML.push_back(strTmp);
    }

    inFile.close();
    return strHTML;
}

vector<string> ParseData(vector<string> s, string pattern) {
    std::vector<std::string> vMatch;
    std::regex word(pattern);

    for(size_t i{0}; i < s.size(); i++) {
        std::sregex_iterator next(s.at(i).begin(), s.at(i).end(), word);
        std::sregex_iterator end;

        while(next != end) {
            smatch match = *next;
            vMatch.push_back(match.str());
            next++;
        }
    }

    return vMatch;
}

bool WriteExtractNews(vector<string>& news, vector<string>& urls) {
    ofstream outFile{"newsToday.txt"};

    if(!outFile) {
        std::cerr << "File not Found\n";
        exit(EXIT_FAILURE);
    }

    for(size_t i{0}; i < news.size(); i++) {
        outFile << news.at(i) << std::endl;
        outFile << urls.at(i) << std::endl;
        //outFile << std::endl;
    }

    outFile.close();
    return true;
}
