package com.dyh.ndkdemo;

import androidx.annotation.LongDef;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.dyh.ndkdemo.jni.JNIAccessFeild;
import com.dyh.ndkdemo.jni.JNIAccessMethod;
import com.dyh.ndkdemo.jni.JNIBasicType;
import com.dyh.ndkdemo.jni.JNIConstructorClass;
import com.dyh.ndkdemo.jni.JNIException;
import com.dyh.ndkdemo.jni.JNIInvokeMethod;
import com.dyh.ndkdemo.jni.JNIReference;
import com.dyh.ndkdemo.jni.JNIReferenceType;
import com.dyh.ndkdemo.jni.JNIString;
import com.dyh.ndkdemo.jni.JNIThread;
import com.dyh.ndkdemo.load.JNIDynamicLoad;
import com.dyh.ndkdemo.thread.ICallbackMethod;
import com.dyh.ndkdemo.thread.IThreadCallback;
import com.dyh.ndkdemo.util.Animal;

public class MainActivity extends AppCompatActivity {

//    // Used to load the 'native-lib' library on application startup.
//    static {
//        System.loadLibrary("native-lib");
//    }

    public String[] strings = {"apple", "pear", "banana"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
//        tv.setText(stringFromJNI());

//        JNIDynamicLoad jniDynamicLoad = new JNIDynamicLoad();
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                tv.setText(jniDynamicLoad.getNativeString());
//            }
//        });

//        JNIBasicType jniBasicType = new JNIBasicType();
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                tv.setText("java show " + jniBasicType.callNativeInt(2));
//
//                Log.d("ndk", "java show " + jniBasicType.callNativeInt(2));
//                Log.d("ndk", "java show " + jniBasicType.callNativeByte((byte)2));
//                Log.d("ndk", "java show " + jniBasicType.callNativeChar('a'));
//                Log.d("ndk", "java show " + jniBasicType.callNativeBoolean(false));
//                Log.d("ndk", "java show " + jniBasicType.callNativeDouble(2.0));
//                Log.d("ndk", "java show " + jniBasicType.callNativeFloat(10.0f));
//                Log.d("ndk", "java show " + jniBasicType.callNativeLong(20L));
//                Log.d("ndk", "java show " + jniBasicType.callNativeShort((short) 4));
//            }
//        });

//        JNIString jniString = new JNIString();
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                Log.d("ndk", jniString.callNativeString("java string"));
//                jniString.stringMethod("java string");
//            }
//        });

//        JNIReferenceType jniReferenceType = new JNIReferenceType();
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                Log.d("ndk", "array item is " + jniReferenceType.callNativeStringArray(strings));
//            }
//        });

//        final JNIAccessFeild feild = new JNIAccessFeild();
//        final Animal animal = new Animal("animal");
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                feild.accessStaticField(animal);
//                feild.accessInstanceField(animal);
//                feild.staticAccessInstanceField();
//
//                Log.d("ndk", "name is " + animal.getName());
//                Log.d("ndk", "num is " + animal.getNum());
//                Log.d("ndk", "num is " + feild.num);
//            }
//        });

//        final JNIAccessMethod jniAccessMethod = new JNIAccessMethod();
//        final Animal animal = new Animal("animal");
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                jniAccessMethod.accessInstanceMethod(animal);
//                jniAccessMethod.accessStaticMethod(animal);
//            }
//        });

//        final JNIInvokeMethod jniInvokeMethod = new JNIInvokeMethod();
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                jniInvokeMethod.nativeCallback(new ICallbackMethod() {
//                    @Override
//                    public void callback() {
//                        Log.d("ndk", "thread name is " + Thread.currentThread().getName());
//                    }
//                });
//
//                jniInvokeMethod.nativeThreadCallback(new IThreadCallback() {
//                    @Override
//                    public void callback() {
//                        Log.d("ndk", "thread name is " + Thread.currentThread().getName());
//                    }
//                });
//            }
//        });

//        final JNIConstructorClass jniConstructorClass = new JNIConstructorClass();
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                Log.d("ndk", "name is " + jniConstructorClass.allocObjectConstructor().getName());
//                Log.d("ndk", "name is " + jniConstructorClass.invokeAnimalConstructors().getName());
//            }
//        });

//        final JNIReference jniReference = new JNIReference();
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                jniReference.cacheWithGlobalReference();
//                jniReference.errorCacheLocalReference();
//                jniReference.useWeakGlobalReference();;
//            }
//        });

//        final JNIException jniException = new JNIException();
//        tv.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                try {
//                    jniException.nativeThrowException();
//                } catch (IllegalArgumentException e) {
//                    Log.d("ndk", e.getMessage());
//                }
//                jniException.nativeInvokeJavaException();
//            }
//        });

        ///////jni操作线程
        final JNIThread jniThread = new JNIThread();
        findViewById(R.id.btn_1).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                jniThread.createNativeThread();
            }
        });
        findViewById(R.id.btn_2).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                jniThread.createNativeThreadWithArgs();
            }
        });
        findViewById(R.id.btn_3).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                jniThread.joinNativeThread();
            }
        });

        findViewById(R.id.btn_4).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                jniThread.waitNativeThread();
            }
        });
        findViewById(R.id.btn_5).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                jniThread.notifyNativeThread();
            }
        });
        findViewById(R.id.btn_6).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                jniThread.startPAndCThread();
            }
        });

        findViewById(R.id.btn_7).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, BitmapActivity.class));
            }
        });


    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
//    public native String stringFromJNI();
//
//    public native String getString();
}