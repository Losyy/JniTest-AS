package cn.com.losy.jnitest.jni;

import android.util.Log;
import java.util.ArrayList;

/**
 * Created by huangximin on 2015/12/24.
 * 说明：本类中以Java层为基本视角
 *       Java层向native层传参称为传入
 *       native层向Java层传参称为传出
 */
public class NativeKit {
    private String name = "Java";

    // 回调方法.native层的doCallback方法会调用本方法
    public void callbackForJni(String fromNative) {
        Log.d("jni", "jni string from native:" + fromNative);
    }

    // 加载so文件
    static {
        System.loadLibrary("JniDemo");
    }

    // 求平方.分别测试int/float/doudle/long的传入和传出
    public native int square(int num);
    public native float square(float num);
    public native double square(double num);
    public native long square(long num);
    // 欢迎词.测试String的传入和传出
    public native String greetings(String username);
    // 获取二维数组.dimon*dimon的int型数组
    public native int[][] getTwoArray(int dimon);
    // 设置name.测试native层直接修改Java类成员变量
    public native void nativeSetName();
    // 回调.这个方法有点绕.native层的doCallback方法会再调用Java层（本类）的callbackForJni方法
    public native void doCallback();
    // 获取User实例.测试native层创建对象,然后返回给Java层
    public native User nativeGetUser();
    // native层获取Java层对象,并获取成员变量
    public native void printUserInfoAtNative(User user);
    // 修改User对象成员变量.同时测试Java层对象的传入、修改、传出
    public native User changeUserInfo(User user);
    // 获取对象列表.测试native层创建Java层对象列表,并返回
    public native ArrayList<User> nativeGetUserList(int num);

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
