package ndk.jesson.com.ndkdemo;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    TextView tv;
    JNIUtils mJNIUtils;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mJNIUtils = new JNIUtils();

        tv = findViewById(R.id.sample_text);
        Button btn1 = findViewById(R.id.btn1);
        Button btn2 = findViewById(R.id.btn2);

        btn1.setOnClickListener(this);
        btn2.setOnClickListener(this);


        tv.setText(JNIUtils.getStringFormC());

    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.btn1:
                //加密
                tv.setText(JNIUtils.encode(tv.getText().toString()));
                break;
            case R.id.btn2:
                tv.setText(JNIUtils.decode(tv.getText().toString()));
                //解密
                break;
        }
    }
}
