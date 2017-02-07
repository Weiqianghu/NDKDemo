package com.huweiqiang.ndkdemo;

/**
 * Description ${Desc}
 * Author huweiqiang
 * Date 2017/2/7.
 */

public class ClassMethod {
    private static void callStaticMethod(String str, int i) {
        System.out.format("ClassMethod::callStaticMethod called!-->str=%s," +
                " i=%d\n", str, i);
    }

    private void callInstanceMethod(String str, int i) {
        System.out.format("ClassMethod::callInstanceMethod called!-->str=%s, " +
                "i=%d\n", str, i);
    }
}
