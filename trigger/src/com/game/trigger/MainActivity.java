package com.game.trigger;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		Button btn = (Button)findViewById(R.id.push);
		btn.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				Toast.makeText(MainActivity.this, ""+callExternal(), Toast.LENGTH_LONG).show();
			}
		});

		Toast.makeText(this, ""+call(), Toast.LENGTH_LONG).show();
	}

	public native int call();
	public native int callExternal();

	static {
        System.loadLibrary("main");
    }
}
