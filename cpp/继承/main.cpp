#include<iostream>
#include "LibMat.h"
#include "AudioBook.h"
using namespace std;
int main(void)
{
				cout<<"\n"<<"creating a libmat object\n";
				AudioBook book("The Castle","Franz Kafka","george");
				print(book);
				return 0;
}
