package com.example.discordlite;

import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("native-lib");
    }

    public native String getDiscordInfo();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TextView view = new TextView(this);
        view.setText(getDiscordInfo());
        setContentView(view);
    }
}
