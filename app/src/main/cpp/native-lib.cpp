#include <jni.h>
#include <string>

const char keyValue[] = {  //秘钥key
        21, 25, 21, 45, 25, 98, 55, 45, 10, 35, 45, 35,
        26, 5, 25, 65, 78, 99, 85, 45, 5, 10, 0, 11,
        35, 48, 98, 65, 32, 14, 67, 25, 36, 56, 45, 5,
        12, 15, 35, 15, 25, 14, 62, 25, 33, 45, 55, 12, 8
};

const char iv[] =  {    //16 bit
        33, 32, 25, 25, 35, 27, 55, 12, 15,32,
        23, 45, 26, 32, 5,16
};


extern "C"
JNIEXPORT jstring JNICALL
Java_ndk_jesson_com_ndkdemo_JNIUtils_getStringFormC(JNIEnv *env, jclass type) {
    return env->NewStringUTF("这是来自C++的原始字符串");
}

/***
 * 获取c++里面的数组jbyte
 */
extern "C"
JNIEXPORT jbyteArray JNICALL
Java_ndk_jesson_com_ndkdemo_JNIUtils_getKeyValue(JNIEnv *env, jclass type) {
    jbyteArray kv = env->NewByteArray(sizeof(keyValue));
    jbyte* bytes = env->GetByteArrayElements(kv,0);

    int i=0;
    for (i;i < sizeof(keyValue); ++i) {
        bytes[i] = keyValue[i];
    }
    env->SetByteArrayRegion(kv,0, sizeof(keyValue),bytes);
    env->ReleaseByteArrayElements(kv,bytes,0);
    return kv;

}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_ndk_jesson_com_ndkdemo_JNIUtils_getIv(JNIEnv *env, jclass type) {

    jbyteArray ivArray = env->NewByteArray(sizeof(iv));
    jbyte *bytes = env->GetByteArrayElements(ivArray, 0);

    int i;
    for (i = 0; i < sizeof(iv); i++){
        bytes[i] = (jbyte)iv[i];
    }

    env->SetByteArrayRegion(ivArray, 0, sizeof(iv), bytes);
    env->ReleaseByteArrayElements(ivArray,bytes,0);
    return ivArray;
}


