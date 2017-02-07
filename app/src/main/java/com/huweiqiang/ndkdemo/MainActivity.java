package com.huweiqiang.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        final TextView sumTv = (TextView) findViewById(R.id.tv_sum);

        findViewById(R.id.btn_say_hello).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv.setText(sayHello("小胡胡"));
            }
        });

        final int[] arr = new int[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }
        findViewById(R.id.btn_sum).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sumTv.setText("The sum is :" + sumArray(arr));
            }
        });

        int[][] array = initInt2DArray(3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.format("arr[%d][%d] = %d\n", i, j, array[i][j]);
            }
        }
    }

    public native String stringFromJNI();

    public native String sayHello(String name);

    public native int sumArray(int[] array);

    private native int[][] initInt2DArray(int size);
}
