//
// Created by huangximin on 2015/12/24.
//

#include <cn_com_losy_jnitest_jni_NativeKit.h>
#include <jni.h>
#include <stdio.h>
#include <cstdio>

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    square
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_square__I
        (JNIEnv * env, jobject obj, jint num) {
    return num * num;
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    square
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_square__F
        (JNIEnv * env, jobject obj, jfloat num) {
    return num * num;
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    square
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_square__D
        (JNIEnv * env, jobject obj, jdouble num) {
    return num * num;
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    square
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_square__J
        (JNIEnv * env, jobject obj, jlong num) {
    return num * num;
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    greetings
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_greetings
        (JNIEnv * env, jobject obj, jstring jstr) {
    // 读取来自Java层的string
    const char* str = env->GetStringUTFChars(jstr, false);
    if(str == NULL) {
        return NULL; /* OutOfMemoryError already thrown */
    }
    // 显示string
    std::printf("%s", str);
    std::printf("\n");

    // 释放资源
    env->ReleaseStringUTFChars(jstr, str);
    // TODO: add jstr
    // 返回新string
    const char* tmpstr = "I am from Jni";
    jstring rtstr = env->NewStringUTF(tmpstr);
    return rtstr;
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    getTwoArray
 * Signature: (I)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_getTwoArray
        (JNIEnv * env, jobject obj, jint dimion) {
    if (dimion > 10) { // 假设 dimion  <= 10 ;
        return NULL;
    }
    // 获得一维数组 的类引用，即jintArray类型
    jclass intArrayClass = env->FindClass("[I");
    // 构造一个指向jintArray类一维数组的对象数组，该对象数组初始大小为dimion
    jobjectArray obejctIntArray = env->NewObjectArray(dimion, intArrayClass, NULL);

    // 构建dimion个一维数组，并且将其引用赋值给obejctIntArray对象数组
    for( int i = 0; i< dimion; i++ ) {
        // 构建jint型一维数组
        jintArray intArray = env->NewIntArray(dimion);
        // 设置jint型一维数组的值
        jint temp[10];  // 初始化一个容器，假设 dimion  <= 10 ;
        for( int j = 0; j < dimion; j++) {
            temp[j] = i + j; //赋值
        }
        // 将temp数组复制到intArray
        env->SetIntArrayRegion(intArray, 0, dimion, temp);
        // 给object对象数组赋值，即保持对jint一维数组的引用
        env->SetObjectArrayElement(obejctIntArray, i, intArray);
        // 删除局部引用
        env->DeleteLocalRef(intArray);
    }

    return  obejctIntArray; // 返回该对象数组
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    nativeSetName
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_nativeSetName
        (JNIEnv * env, jobject obj) {
    jclass cls = env->GetObjectClass(obj); //获得Java层该对象实例的类引用，即NativeKit类引用

    jfieldID nameFieldId = env->GetFieldID(cls, "name", "Ljava/lang/String;"); //获得属性句柄

    if(nameFieldId == NULL) {
        std::printf(" 没有得到name 的句柄Id \n;");
    }
    jstring javaNameStr = (jstring) env->GetObjectField(obj ,nameFieldId); // 获得该属性的值
    const char * c_javaName = env->GetStringUTFChars(javaNameStr , NULL); //转换为 char *类型

    std::printf("%s", c_javaName); //输出显示
    std::printf("\n");

    env->ReleaseStringUTFChars(javaNameStr , c_javaName);  //释放局部引用

    // 构造一个jString对象
    const char * c_ptr_name = "setByNative";
    jstring cName = env->NewStringUTF(c_ptr_name);

    env->SetObjectField(obj, nameFieldId, cName); // 设置该字段的值
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    doCallback
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_doCallback
        (JNIEnv * env, jobject obj) {
    jclass cls = env->GetObjectClass(obj); // 获得NativeKit类引用
    jmethodID callbackMethodID = env->GetMethodID(cls, "callbackForJni", "(Ljava/lang/String;)V"); // 获得该回调方法句柄

    if(callbackMethodID == NULL) {
        std::printf("doCallback getMethodId is failed \n");
    }

    jstring native_desc = env->NewStringUTF("callback From Native");

    // 回调该方法，并且传递参数值
    env->CallVoidMethod(obj, callbackMethodID, native_desc);
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    nativeGetUser
 * Signature: ()Lcn/com/losy/jnitest/jni/User;
 */
JNIEXPORT jobject JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_nativeGetUser
        (JNIEnv * env, jobject obj) {
    jclass usercls = env->FindClass("cn/com/losy/jnitest/jni/User"); // 获取User对象引用

    //获得得该类型的构造函数  函数名为 <init> 返回类型必须为 void 即 V
    jmethodID constructMID = env->GetMethodID(usercls,"<init>","(ILjava/lang/String;)V");

    jstring name = env->NewStringUTF("HXM from Native");

    // 构造一个对象，调用该类的构造函数，并且传递参数
    jobject userojb = env->NewObject(usercls, constructMID, 11, name);

    return userojb;
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    printUserInfoAtNative
 * Signature: (Lcn/com/losy/jnitest/jni/User;)V
 */
JNIEXPORT void JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_printUserInfoAtNative
        (JNIEnv * env, jobject obj, jobject userobj) {
    jclass usercls = env->GetObjectClass(userobj); // 或得User类引用

    if(usercls == NULL) {
        std::printf("GetObjectClass failed \n");
    }

    jfieldID ageFieldID = env->GetFieldID(usercls,"age","I"); //获得得Student类的属性id
    jfieldID nameFieldID = env->GetFieldID(usercls,"name","Ljava/lang/String;"); // 获得属性ID

    jint age = env->GetIntField(userobj , ageFieldID);  //获得属性值
    jstring name = (jstring)env->GetObjectField(userobj , nameFieldID);//获得属性值

    const char * c_name = env->GetStringUTFChars(name, false);// 转换成 char *

    // 显示user信息
    std::printf("show user info age:%d name:%s", age, c_name);

    env->ReleaseStringUTFChars(name, c_name); //释放引用
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    changeUserInfo
 * Signature: (Lcn/com/losy/jnitest/jni/User;)Lcn/com/losy/jnitest/jni/User;
 */
JNIEXPORT jobject JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_changeUserInfo
        (JNIEnv * env, jobject obj, jobject userobj) {
    jclass usercls = env->GetObjectClass(userobj); // 或得User类引用

    if(usercls == NULL) {
        std::printf("GetObjectClass failed \n");
    }

    jfieldID ageFieldID = env->GetFieldID(usercls,"age","I"); // 获得得User类的属性id
    jfieldID nameFieldID = env->GetFieldID(usercls,"name","Ljava/lang/String;"); // 获得属性ID

    jint age = env->GetIntField(userobj, ageFieldID);  // 获得属性值
    jstring name = (jstring)env->GetObjectField(userobj, nameFieldID);// 获得属性值

    const char * c_name = env->GetStringUTFChars(name, false);// 转换成 char *

    // 显示user信息
    std::printf("show user info age:%d name:%s", age, c_name);

    env->ReleaseStringUTFChars(name, c_name); //释放引用

    // 构造一个jString对象
    const char * c_ptr_name = "quyuan";
    jstring cName = env->NewStringUTF(c_ptr_name);
    env->SetObjectField(userobj, nameFieldID, cName); // 设置该字段的值

    env->SetIntField(userobj, ageFieldID, 55); // 设置该字段的值

    return userobj;
}

/*
 * Class:     cn_com_losy_jnitest_jni_NativeKit
 * Method:    nativeGetUserList
 * Signature: (I)Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_cn_com_losy_jnitest_jni_NativeKit_nativeGetUserList
        (JNIEnv * env, jobject obj, jint size) {
    jclass listcls = env->FindClass("java/util/ArrayList");// 获得ArrayList类引用

    if(listcls == NULL) {
        std::printf("listcls is null \n");
    }
    jmethodID list_construct = env->GetMethodID(listcls , "<init>","()V");// 获得得构造函数Id

    jobject listobj = env->NewObject(listcls, list_construct); // 创建一个Arraylist集合对象
    // 获得Arraylist类中的 add()方法ID，其方法原型为： boolean add(Object object) ;
    jmethodID list_add  = env->GetMethodID(listcls,"add","(Ljava/lang/Object;)Z");

    jclass usercls = env->FindClass("cn/com/losy/jnitest/jni/User"); // 获得User类引用
    //获得该类型的构造函数  函数名为 <init> 返回类型必须为 void 即 V
    jmethodID user_costruct = env->GetMethodID(usercls , "<init>", "(ILjava/lang/String;)V");

    for(int i = 0; i < size; i++) {
        jstring str = env->NewStringUTF("Native");
        //通过调用该对象的构造函数来new 一个 Student实例
        jobject stu_obj = env->NewObject(usercls , user_costruct, 10, str);  //构造一个对象

        env->CallBooleanMethod(listobj, list_add, stu_obj); // 执行Arraylist类实例的add方法，添加一个stu对象
    }

    return listobj ;
}
