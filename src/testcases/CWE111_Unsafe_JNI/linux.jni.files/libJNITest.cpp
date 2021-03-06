/*
 * @description This method takes in a string and an int.  It copies whats in the string
 * into a fixed buffer of length 10.  However, if the user can control the integer
 * argument, bad things can happen. :)
 *
 * This file was compiled in a Linux envrionment with the following command lines:
 *		g++ -I /root/jdk1.6.0_27/include/linux/ -I /root/jdk1.6.0_27/include/ -c -fpic libJNITest.cpp
 *		g++ -I /root/jdk1.6.0_27/include/linux/ -I /root/jdk1.6.0_27/include/ -shared -lc -o libJNITest.so libJNITest.o
 *
 * NOTE: You must specify the location of jni.h and the linux specific jni headers (as seen in the include paths above)
 * 
 * */

#include "JNITest.h"
#include <string.h>

/* The function name has to be "encoded";
 * I autogenerated the function name using javah.
 * Basically, it follows the encoding process on this webpage:
 * http://java.sun.com/javase/6/docs/technotes/guides/jni/spec/design.html
 */
JNIEXPORT jstring JNICALL Java_testcases_CWE111_1Unsafe_1JNI_console_CWE111_1Unsafe_1JNI_1_1console_101_test(
	JNIEnv *jenv, 
	jobject jobj, 
	jstring str, 
	jint length
	)
{
	char result[10];

	const char *mfile = (jenv)->GetStringUTFChars(str, NULL);

	strncpy(result, mfile, length);
	result[length] = '\0';

	(jenv)->ReleaseStringUTFChars(str, mfile);

	return (jenv)->NewStringUTF(result);
}
