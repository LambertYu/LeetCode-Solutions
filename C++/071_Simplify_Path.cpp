#include <string>
#include <iostream>
#include <stack>

std::string simplifyPath(const std::string& path) {
  int size = path.size();
  std::stack<char> sPath;
  for(int i = 0; i < size; i++){
    if(path[i] == '/' && (i == 0 || sPath.empty() )){
      sPath.push(path[i]);
    }
    if(!sPath.empty()){
      if(path[i] == '.'){
        while(sPath.top() != '/') sPath.pop();
        sPath.pop();
      }else if(path[i] == '/'){
        if(sPath.top() != '/') sPath.push(path[i]);
      }else{
        sPath.push(path[i]);
      }
    }
  }
  if(sPath.top() == '/' && sPath.size() > 1) sPath.pop();
  // std::string newPath(sPath.size(), ' ');
  // int i = sPath.size() - 1;
  // for(; i >= 0; i--) {
  //   newPath[i] = sPath.top();
  //   sPath.pop();
  // }
  std::string newPath = "";
  int len = sPath.size();
  for(int i = 0; i < len; i++) {
    newPath = sPath.top() + newPath;
    sPath.pop();
  }
  return newPath;
}

int main(){
  std::string path = "/a/./b/../../c/";
  //std::string path = "/home/";
  //std::string path = "/../";
  //std::string path = "/home//foo/";
  std::string result = simplifyPath(path);
  std::cout << result << '\n';
}
