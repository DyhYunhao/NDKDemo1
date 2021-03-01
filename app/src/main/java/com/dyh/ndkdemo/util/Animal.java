package com.dyh.ndkdemo.util;

import android.util.Log;

/**
 * describe: 演示调用java类的示例类
 * create by daiyh on 2021-2-24
 */
public class Animal {
    protected String name;
    public static int num = 0;

    public Animal(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public static int getNum() {
        return num;
    }

    //c++调用java的实例方法
    public void callInstanceMethod(int num) {
        Log.d("ndk", "callInstanceMethod: num is " + num);
    }

    //c++调用java的类方法
    public static String callStaticMethod(String str) {
        if (str != null) {
            Log.d("ndk", "callStaticMethod: with " + str);
        } else {
            Log.d("ndk", "callStaticMethod: str is null");
        }
        return "";
    }

    //c++调用和java的静态方法
    public static String callStaticMethod(String[] strs, int num) {
        if (strs != null) {
            for (String str: strs) {
                Log.d("ndk", "callStaticMethod: str in array is " + str);
            }
        }
        return "";
    }
}
