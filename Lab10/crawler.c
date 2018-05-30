#define REP_TYPE_LIST
#include "graph.h"
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
Graph* createNode_URL(void *ptr, size_t size, size_t nmemb, void *stream){
	size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  
}
Graph* crawl(char *name){
	char *url=(char*)malloc(sizeof(char)*100);
	strcpy(url, name);
	Graph *g=createGraph(200);
	CURL *curl_handle;
  static const char *webfilename = "out";
  FILE *webfile;
  Queue *q=newQ();
  q=addQ(returnEle(url));
  //initialize curl global environment
  curl_global_init(CURL_GLOBAL_ALL);

  /* init the curl session */
  curl_handle = curl_easy_init();
	
  while(!isEmptyQ(q)){
  	url=front(q); q=delQ(q);
  	/* set URL to get */
  	curl_easy_setopt(curl_handle, CURLOPT_URL, url);

  	/* no progress meter please */
 	 curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

  	/* send all data to this function  */
  	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, createNode_URL);

  	/* open the web file */
  	webfile = fopen(webfilename, "wb");
  	if(!webfile) {
  	  curl_easy_cleanup(curl_handle);
    	return -1;
  	}

  	/* we want the body be written to this file handle instead of stdout 			*/
  	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, webfile);

  	/* get it! */
  	curl_easy_perform(curl_handle);
  	char *x="href=";
  	char *y=">";
  	while(!feof(c)){
  		//get all links and add to queue
  	}
	}
  /* close the web file */
  fclose(webfile);

  /* cleanup curl stuff */
  curl_easy_cleanup(curl_handle);

}
