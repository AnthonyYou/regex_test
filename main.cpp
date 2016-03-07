#include <iostream>
#include <boost/regex.hpp>
#include <curl.h>

using namespace std;

void parseContent(const string &content) {
    const char *szReg = "<div.*?content\">\\s*(?'word'[\\w\\W]*?)<!--(?'id'\\d*)-->";
    boost::regex reg(szReg);
    boost::regex brReg("<br\\s*/>");
    boost::match_results<string::const_iterator> what;
    string::const_iterator start(content.begin());
    while(boost::regex_search(start, content.end(), what, reg, boost::match_default)) {
//        cout << what["word"] << endl;
        string converted = boost::regex_replace(what["word"].str(), brReg, "\n");
        string id = what["id"].str();
        cout << "id = " << id << endl;
        cout << converted << endl;
        start = what[0].second;
    }
}

//void parseContent(const string &content) {
//    const char *szReg = "<div.*?content\">\\s*(?'word'[\\w\\W]*?)<!--(?'id'\\d*)-->";
//    boost::regex reg(szReg);
//    boost::match_results<string::const_iterator> what;
//    string::const_iterator start(content.begin());
//    while(boost::regex_search(start, content.end(), what, reg, boost::match_default)) {
//        string word = what["word"].str();
//        string id = what["id"].str();
//        cout << "id = " << id << endl;
//        cout << word << endl;
//        start = what[0].second;
//    }
//}

size_t onWriteData(void *buffer, size_t size, size_t nmemb, void *str) {
    if(!str || !buffer) {
        return -1;
    }
    string *result = (string*)str;
    result->append((char*)buffer, size * nmemb);
    return nmemb;
}

int main() {
    string result;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.qiushibaike.com/hot/page/2/");
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
    curl_easy_setopt(curl, CURLOPT_POST, 0);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.86 Safari/537.36");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, onWriteData);
    curl_easy_perform(curl);


    long code = 5;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
    if(code == 200) {
        parseContent(result);
//        cout << result << endl;
    }
    curl_easy_cleanup(curl);

    return 0;
}
