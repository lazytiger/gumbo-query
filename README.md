# gumbo-query
A C++ library that provides jQuery-like selectors for Google's Gumbo-Parser.
Selector engine is an implementation based on [cascadia](code.google.com/p/cascadia).

## Installation
2 ways:
1. Through homebrew (Recommended):
```bash
$ brew install gumbo-query
```
2. Through git:
```bash
$ git clone https://github.com/Falven/gumbo-query
$ cd gumbo-query/build && cmake .. && make && make test
$ sudo make install
```

## Usage
```C++
#include <iostream>
#include <string>
#include "Document.h"
#include "Node.h"

int main(int argc, char * argv[])
{
  std::string page("<h1><a>some link</a></h1>");
  CDocument doc;
  doc.parse(page.c_str());

  CSelection c = doc.find("h1 a");
  std::cout << c.nodeAt(0).text() << std::endl; // some link
  return 0;
}
```
