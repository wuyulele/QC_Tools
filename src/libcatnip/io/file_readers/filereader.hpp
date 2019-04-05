
#ifndef _CATNIP_FILEREADER_HPP_
#define _CATNIP_FILEREADER_HPP_

#include <string>
#include <fstream>
#include <set>
#include <map>

namespace catnip {

struct FilePackage{
  void * ptr;
};

class FileReader{
  public:
    FileReader(const std::string & fileName) : fileName_(fileName) {};    
    std::string getExt() const;

    void read();
  protected:

    typedef void (*FRfunc)(void *);

    // Private members
    void open();
    void close();
    virtual void registerSections_();
    virtual void validFileName_() {};
    void checkSections_();
    void readSection_(std::string tag);
    std::string startSection_(const std::string & tag);
    std::string fileExt_() const;
    bool fileExist_() const; 
    // Private attributes
    // key - stores tag of the section
    // value - stores the pattern used to identify the section
    std::map<std::string,std::set<std::string>> sectionHeaders_;
    // key - stores tag of the section
    // value - stores the section reader function
    std::map<std::string,FRfunc > sectionReaders_;

    std::string fileName_;
    std::ifstream fid_;
    std::streampos pos_;
    bool fileOpen_ = false;
};

}
#endif // _CATNIP_FILEREADER_HPP_