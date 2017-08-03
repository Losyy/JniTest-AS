/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class cn_com_losy_jnitest_jni_NativeKit */

#ifndef _Included_cn_com_losy_jnitest_jni_NativeKit
#define _Included_cn_com_losy_jnitest_jni_NativeKit
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    square
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_square__I
  (JNIEnv *, jobject, jint);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    square
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_square__F
  (JNIEnv *, jobject, jfloat);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    square
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_square__D
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    square
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_square__J
  (JNIEnv *, jobject, jlong);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    greetings
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_greetings
  (JNIEnv *, jobject, jstring);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    getTwoArray
 * Signature: (I)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_getTwoArray
  (JNIEnv *, jobject, jint);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    nativeSetName
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_nativeSetName
  (JNIEnv *, jobject);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    doCallback
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_doCallback
  (JNIEnv *, jobject);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    nativeGetUser
 * Signature: ()Lcn/com/losy/jnitest/jni/User;
 */
JNIEXPORT jobject JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_nativeGetUser
  (JNIEnv *, jobject);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    printUserInfoAtNative
 * Signature: (Lcn/com/losy/jnitest/jni/User;)V
 */
JNIEXPORT void JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_printUserInfoAtNative
  (JNIEnv *, jobject, jobject);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    changeUserInfo
 * Signature: (Lcn/com/losy/jnitest/jni/User;)Lcn/com/losy/jnitest/jni/User;
 */
JNIEXPORT jobject JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_changeUserInfo
  (JNIEnv *, jobject, jobject);

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    nativeGetUserList
 * Signature: (I)Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_nativeGetUserList
  (JNIEnv *, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif
