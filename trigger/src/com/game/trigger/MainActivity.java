package com.game.trigger;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;
import android.view.View;
import android.widget.Button;
import android.content.Context;
import android.content.Intent;
import com.example.SanAngeles.*;

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
				Toast.makeText(MainActivity.this, "tinyxml2: "+callTinyXML(), Toast.LENGTH_LONG).show();
			}
		});

		Button physfs = (Button)findViewById(R.id.physfs);
		physfs.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				Toast.makeText(MainActivity.this, "physfs: "+callPHYSFS(), Toast.LENGTH_LONG).show();
			}
		});

		Button san = (Button)findViewById(R.id.san);
		san.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				MainActivity.this.startActivity(new Intent(MainActivity.this, DemoActivity.class));
			}
		});
	}

	public native String callTinyXML();
	public native String callPHYSFS();

	static {
        System.loadLibrary("main");
    }
}
