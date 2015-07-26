//
//  main.c
//  rooun
//
//  Created by 3x7R00Tripper on 31.12.13.
//  Copyright (c) 2013 3x7R00Tripper. All rights reserved.
//
#include <curl/curl.h>
#include <curl/easy.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
}
void downloadapp() {
    system("cd /tmp; mkdir -p WWDC");
    CURL *curl;
    CURLcode curl_res;
    CURLINFO info;
    long http_code;
    double c_length;
    FILE *tmp;
    tmp=fopen("/tmp/WWDC/wwdc.ipa", "w");
    if(tmp==NULL) {
        printf("Error to download file\n");
        exit(2);
    }
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://a396.phobos.apple.com/us/r1000/098/Purple/v4/c3/4e/98/c34e989a-8522-fde0-db2d-884dd3b1302d/mzps6036043982514941651.D2.pd.ipa");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, tmp);
    curl_easy_setopt(curl, CURLOPT_COOKIE, "downloadKey=expires=1388667604~access=/us/r1000/098/Purple/v4/c3/4e/98/c34e989a-8522-fde0-db2d-884dd3b1302d/mzps6036043982514941651.D2.pd.ipa*~md5=2e943e2f3b9e1143f3e1588fd7c1c9e0");
    curl_res = curl_easy_perform(curl);
    if(curl_res==0) {
        printf(" [*] WWDC downloaded successfully\n");
    } else {
        printf("ERROR in dowloading file\n");
        fclose(tmp);
        curl_easy_cleanup(curl);
    }
    fclose(tmp);
    curl_easy_cleanup(curl);
}

void injectionapp1() {
    system("cd /tmp/rootun; ./afcclient mkdir Downloads/WWDC.app; ./afcclient put /tmp/WWDC/Payload/WWDC.app/WWDC Downloads/WWDC.app/WWDC");
    system("cd /tmp/rootun; ./afcclient put /tmp/rootun/jailbreak.png /rootun-install/jailbreak.png");
}
void injectionapp2() {
    system("cd /tmp/WWDC; unzip wwdc.ipa > /dev/null");
	system("cd /tmp/WWDC; cp /tmp/rootun/Info.plist Payload/WWDC.app/Info.plist > /dev/null");
	system("cd /tmp/WWDC; zip -r /tmp/WWDC/rootun.ipa Payload/ META-INF/ > /dev/null");
    system("cd /tmp/rootun; ./afcclient put /tmp/WWDC/rootun.ipa /rootun-install/rootun.ipa");
    
}
int main() {
    printf(" [*] Starting Installation of personnalized app !\n");
    printf(" [*] Thank you for using F4k3r1P4 From Lilo Colson (@Pwn1d).\n");
    printf(" [*] Retrieving remote package...\n");
    downloadapp();
    printf(" [*] Unpacking WWDC\n");
    printf(" [*] Injecting rootun app (1/2)\n");
    injectionapp1();
    printf(" [*] Injecting rootun app (2/2)\n");
    injectionapp2();
}
