package cn.com.losy.jnitest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import java.util.ArrayList;

import cn.com.losy.jnitest.jni.NativeKit;
import cn.com.losy.jnitest.R;
import cn.com.losy.jnitest.jni.User;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jniTest();
    }

    private void jniTest() {
        NativeKit nativeKit = new NativeKit();
        Log.d("jni", "jni ");
        Log.d("jni", "jni ");
        Log.d("jni", "jni ");
        Log.d("jni", "jni ");
        Log.d("jni", "jni " + "nativeKit.name=" + nativeKit.getName());
        Log.d("jni", "jni " + "int square(2)=" + nativeKit.square(2));
        Log.d("jni", "jni " + "int square(2.7f)=" + nativeKit.square(2.7f));
        Log.d("jni", "jni " + "int square(25l)=" + nativeKit.square(25l));
        Log.d("jni", "jni " + "int square(2.36d)=" + nativeKit.square(2.36d));
        Log.d("jni", "jni " + "greetings:" + nativeKit.greetings(" huangximin "));
        nativeKit.nativeSetName();
        Log.d("jni", "jni " + "nativeKit.name=" + nativeKit.getName());
        nativeKit.doCallback();
        Log.d("jni", "jni " + "user from jni " + nativeKit.nativeGetUser());
        nativeKit.printUserInfoAtNative(new User(18, "YYYY"));
        User user = nativeKit.changeUserInfo(new User(500, "qitiandasheng"));
        Log.d("jni", "jni " + "user=" + user);

        ArrayList<User> userList = nativeKit.nativeGetUserList(3);
        for (User user1 : userList) {
            Log.d("jni", "jni " + "user in userList " + user1);
        }

        int[][] intss = nativeKit.getTwoArray(5);
        Log.d("jni", "jni intss: " + intss);
        for (int[] ints : intss) {
            for (int i : ints) {
                Log.d("jni", "jni i=" + i);
            }
        }

        Log.d("jni", "jni ");
        Log.d("jni", "jni ");
        Log.d("jni", "jni ");
        Log.d("jni", "jni ");
    }
}
