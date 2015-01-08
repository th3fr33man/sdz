package com.orion.dialoguesdz1;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.FragmentManager;
import android.support.v7.app.ActionBarActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

/**
 * 
 * @author th3fr33mn
 * la méthode showDialog est obso il faut maintenant utiliser la méthode avec les fragments
 * 2 exemples présentés l'un avec la méthode récupérant un layout XML dans lequel on peu intégrer aux besoins
 * des boutons oui/non ou ok. L'autre avec la méthode de programmation.
 * 
 * merci a openclassroom.com et androidbegin.com
 * 
 * Les classes secondaires ont été intégrées directement dans la classe principale
 */

public class MainActivity extends ActionBarActivity {

	private final int COMPTEUR_LIMITE = 5;
	private int compteur = 0;
	Button btn_aff_dial = null;

	FragmentManager fm = getSupportFragmentManager();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		btn_aff_dial = (Button)findViewById(R.id.btn_dial);
		btn_aff_dial.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View v) {
				
				// Avec la méthode XML
				//DFragment dFragment = new DFragment();
				//dFragment.show(fm, "Dialog Fragment");
				
				//avec la méthode programmation
				AlertDFragment alert = new AlertDFragment();
				alert.show(fm, "Dialog alert fragment");

			}
		});


	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}


	///Exemple en passant par un fichier XML
	public class DFragment extends DialogFragment {
		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.dialogfragment, container, false);
			TextView text = (TextView)rootView.findViewById(R.id.txt_dialog);

			if(compteur < COMPTEUR_LIMITE)
			{
				getDialog().setTitle("master dialog");
				switch(compteur)
				{
				case 0:
					text.setText("hello i'm here!!");
					break;
				case 1:
					text.setText("hello it's me again!!");
					break;
				case 2:
					text.setText("hello i'm the best dialog box in the world!!");
					break;
				case 3:
					text.setText("hello i'm the best dialog box of the universe!!");
					break;
				case 4:
					text.setText("hello you're boring you know that?");
					break;
				}
				compteur++;
			}
			else
			{
				getDialog().setTitle("secondary dialog");
				text.setText("don't let me alone please!!");
				compteur = 0;
			}
			return rootView;
		}
	}

	//Exemple en passant par par le AlertDialog.Builder
	public class AlertDFragment extends DialogFragment {
		@Override
		public Dialog onCreateDialog(Bundle savedInstanceState) {
			AlertDialog alert = new AlertDialog.Builder(getActivity())
			// Set Dialog Title
			.setTitle("Alert DialogFragment")
			// Set Dialog Message
			.setMessage("Alert DialogFragment Tutorial")
			
			// Positive button
			.setPositiveButton("OK", new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int which) {
					// Do something else
					
				}
			})

			// Negative Button
			.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog,	int which) {
					// Do something else
				}
			}).create();
			
			if(compteur < COMPTEUR_LIMITE)
			{
				alert.setTitle("master dialog");
				switch(compteur)
				{
				case 0:
					alert.setMessage("hello i'm here!!");
					break;
				case 1:
					alert.setMessage("hello it's me again!!");
					break;
				case 2:
					alert.setMessage("hello i'm the best dialog box in the world!!");
					break;
				case 3:
					alert.setMessage("hello i'm the best dialog box of the universe!!");
					break;
				case 4:
					alert.setMessage("hello you're boring you know that?");
					break;
				}
				compteur++;
			}
			else
			{
				alert.setTitle("secondary dialog");
				alert.setMessage("don't let me alone please!!");
				compteur = 0;
			}
			
			
			return alert;
		}
	}
}


