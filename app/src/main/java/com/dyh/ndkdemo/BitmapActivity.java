package com.dyh.ndkdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

import com.dyh.ndkdemo.jni.JNIBitmap;
import com.dyh.ndkdemo.jni.JNIThread;

public class BitmapActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bitmap);

        final ImageView imageView = findViewById(R.id.iv_img_bitmap);
        final Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.mipmap.t);
        final JNIBitmap jniBitmap = new JNIBitmap();
        imageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Bitmap result = jniBitmap.callNativeMirrorBitmap(bitmap);
                imageView.setImageBitmap(result);
            }
        });
    }
}