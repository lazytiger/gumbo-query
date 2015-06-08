#include <Document.h>
#include <Selection.h>
#include <Node.h>

void test_parser() {
	std::string page("<h1><a>wrong link</a><a class=\"special\"\\>some link</a></h1>");
	CDocument doc;
	doc.parse(page.c_str());

	CSelection c = doc.find("h1 a.special");
	printf("Node: %s\n", c.nodeAt(0).text().c_str());
}

int main() {
	while(true) {
	test_parser();	
	}
}
