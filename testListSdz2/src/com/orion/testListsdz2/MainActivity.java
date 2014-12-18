package com.orion.testListsdz2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.GridView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class MainActivity extends ActionBarActivity {
	
	ListView vue;
	GridView vueGrid;
	Button btnTest = null;
	Button btnTestRemove = null;
	ListAdapter adapter = null;
	List<HashMap<String, String>> liste = new ArrayList<HashMap<String, String>>();
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		btnTest = (Button)findViewById(R.id.btn_test);
		btnTestRemove = (Button)findViewById(R.id.btn_testRemove);
		
		//On récupère une ListView de notre layout en XML, c'est la vue qui représente la liste
//	    vue = (ListView) findViewById(R.id.list);
	    vueGrid = (GridView)findViewById(R.id.listGrid);
	    
	    String[][] repertoire = new String[][]{
	      {"Bill Gates", "06 06 06 06 06"},
	      {"Niels Bohr", "05 05 05 05 05"},
	      {"Alexandre III de Macédoine", "04 04 04 04 04"}};

	    
	    
	    HashMap<String, String> element;
	    //Pour chaque personne dans notre répertoire…
	    for(int i = 0 ; i < repertoire.length ; i++) {
	      element = new HashMap<String, String>();
	      element.put("text1", repertoire[i][0]);
	      element.put("text2", repertoire[i][1]);
	      liste.add(element);
	    }
	    
	    
	    
	    btnTest.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				HashMap<String, String> newMap = new HashMap<String, String>();
				newMap.put("text1", "boby lapointe");
				newMap.put("text2", "0607080910");
				liste.add(newMap);
				majNewAdapter(liste);
				
			}
		});
	    
	    btnTestRemove.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				int listLong = liste.size();
				liste.remove(listLong-1);
				majNewAdapter(liste);
			}
		});
	    
	    majNewAdapter(liste);
//	    adapter = new SimpleAdapter(this, liste, android.R.layout.simple_list_item_2, new String[] {"text1", "text2"}, new int[] {android.R.id.text1, android.R.id.text2 });
	    //Pour finir, on donne à la ListView le SimpleAdapter
//	    vue.setAdapter(adapter);
//	    vueGrid.setAdapter(adapter);
	}
	
	public void majNewAdapter(List<HashMap<String, String>> list)
	{
		adapter = null;
		adapter = new SimpleAdapter(this, liste, android.R.layout.simple_list_item_2, new String[] {"text1", "text2"}, new int[] {android.R.id.text1, android.R.id.text2 });
		vueGrid.setAdapter(adapter);
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
}
