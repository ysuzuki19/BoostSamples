#include <iostream>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
namespace fs = boost::filesystem;
using namespace std;

boost::filesystem::path find_git_root (boost::filesystem::path directory) {
  for (auto& filename : fs::directory_iterator (directory)) {
    if (filename.path ().leaf ().string () == ".git") {
      return directory;
    }
  }

  if (directory.branch_path () == getenv("HOME")) {
    return boost::filesystem::path ();
  }

  return find_git_root (directory.branch_path ());
}

int main (int argc, char** argv) {
  fs::path git_root = find_git_root (fs::current_path ());
  std::cout << "GIT ROOT DIR : " << git_root << std::endl;
  return 0;
}
