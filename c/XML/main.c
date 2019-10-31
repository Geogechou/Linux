#include <stdio.h>
#include <stdlib.h>
#include <libxml2/libxml/tree.h>
#include <libxml2/libxml/parser.h>
int main() {

    xmlDocPtr doc=NULL;
    xmlNodePtr root=NULL,cur=NULL;
    xmlKeepBlanksDefault(0);
    const char* doc_name="/home/george/Documents/CLionProjects/XML/test.xml";
    doc=xmlReadFile(doc_name,"UTF-8",XML_PARSE_RECOVER);
    if(doc==NULL){
        fprintf(stderr,"error!can't open the file");
        exit(-1);
    }
    root=xmlDocGetRootElement(doc);
    if(root==NULL){
        fprintf(stderr,"file is empty");
        exit(-1);
    }
    cur=root->children;
    while(cur!=NULL){
        //BAD_CAST是一个宏,转换char到xmlChar,相当于(xmlChar*)
        //寻找等于<book>的标签,xmlStrcmp()==0意味着匹配,这里与strcmp()类似的返回值
        if(0==xmlStrcmp(cur->name,BAD_CAST("book"))){
            xmlNodePtr nptr= cur->children;
            while(nptr!=NULL){
                if(0==xmlStrcmp(nptr->name,BAD_CAST("title"))){
                    printf("title:%s\n",(char*)XML_GET_CONTENT(nptr->children));
                }else if(0==xmlStrcmp(nptr->name,BAD_CAST("price"))){
                    printf("price:%s\n",(char*)XML_GET_CONTENT(nptr->children));
                }
                nptr=nptr->next;
            }
        }
       cur=cur->next;
    }
    xmlFreeDoc(doc);
    xmlCleanupParser();
    xmlMemoryDump();
    return 0;
}