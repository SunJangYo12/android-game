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
				Toast.makeText(MainActivity.this, "xx", Toast.LENGTH_LONG).show();
			}
		});

		Button btnxml = (Button)findViewById(R.id.tinyxml);
		btnxml.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				Toast.makeText(MainActivity.this, ""+callTinyXML(), Toast.LENGTH_LONG).show();
			}
		});

	}

	public native String callTinyXML();

	static {
        System.loadLibrary("main");
    }
}
