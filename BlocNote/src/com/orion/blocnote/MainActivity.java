package com.orion.blocnote;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.text.Editable;
import android.text.Html;
import android.text.TextWatcher;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RadioGroup.OnCheckedChangeListener;
import android.widget.RelativeLayout;
import android.widget.TextView;

public class MainActivity extends ActionBarActivity {
	
	private Button hideShow = null;
	private Slider slider = null;
	private RelativeLayout toHide = null;
	
	private EditText editText = null;
	private TextView resultText = null;
	private Button btnGras = null;
	private Button btnItalique = null;
	private Button btnSouligne = null;
	private Button btnSmileySourire =  null;
	private Button btnSmileyGrosSourire =  null;
	private Button btnSmileyClinDOeil =  null;
	private RadioButton rbtnCouleurNoir = null;
	private RadioButton rbtnCouleurBleu = null;
	private RadioButton rbtnCouleurRouge = null;
	
	private RadioGroup colorChooser = null;
	
	private String currentColor = "#000000";
	private Smiley getter = null;
	
	
	
	

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		
		editText = (EditText)findViewById(R.id.edit_edition);
		resultText = (TextView)findViewById(R.id.txt_result);
		btnGras = (Button)findViewById(R.id.btn_gras);
		btnItalique = (Button)findViewById(R.id.btn_italique);
		btnSouligne = (Button)findViewById(R.id.btn_souligne);
		btnSmileySourire = (Button)findViewById(R.id.smiley_sourire);
		btnSmileyGrosSourire = (Button)findViewById(R.id.smiley_gros_sourire);
		btnSmileyClinDOeil = (Button)findViewById(R.id.smiley_clin_oeil);
//		rbtnCouleurNoir = (RadioButton)findViewById(R.id.rbtn_noir);
//		rbtnCouleurBleu = (RadioButton)findViewById(R.id.rbtn_bleu);
//		rbtnCouleurRouge = (RadioButton)findViewById(R.id.rbtn_rouge);
		colorChooser = (RadioGroup)findViewById(R.id.rgrp_color);
		getter = new Smiley(this);
		
		
		//On récupère le bouton pour cacher/afficher le menu
        hideShow = (Button) findViewById(R.id.btn_hide);
        //Puis, on recupère la vue racine de l'application et on change sa couleur
        hideShow.getRootView().setBackgroundColor(getResources().getColor(R.color.background));
        //On rajoute un Listener sur le clic du bouton...
        hideShow.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View vue) {
				//...pour afficher ou cache le menu
				if(slider.toggle())
				{
					//Si le Slider est ouvert...
					//... on change le texte en "Cacher"
					hideShow.setText(R.string.txt_cacher);
				}else
				{
					//Sinon on met "Afficher"
					hideShow.setText(R.string.txt_afficher);
				}
			}
		});

        //On récupère le menu
        toHide = (RelativeLayout) findViewById(R.id.menu);
        //On récupère le layout principal
        slider = (Slider) findViewById(R.id.slider);
        //On donne le menu au layout principal
        slider.setToHide(toHide);
		
		//===== Listener
		// @TODO : prévoir une modification qui permet d'écrire en gras/italique/souligne en dynamique tant que le bouton est actif
		OnClickListener onClickBalise = new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				int selStart = editText.getSelectionStart();
				int selEnd = editText.getSelectionEnd();
				Editable editable = editText.getText();
				switch (v.getId()) {
				case R.id.btn_gras:
					if(selStart == selEnd)
					{
						editable.insert(selStart, "<b></b>");
					}
					else
					{
						editable.insert(selStart, "<b>");
						editable.insert(selEnd + 3 , "</b>");
					}
					break;
				case R.id.btn_italique:
					if(selStart == selEnd)
					{
						editable.insert(selStart, "<i></i>");
					}
					else
					{
						editable.insert(selStart, "<i>");
						editable.insert(selEnd + 3 , "</i>");
					}
					break;
				case R.id.btn_souligne:
					if(selStart == selEnd)
					{
						editable.insert(selStart, "<u></u>");
					}
					else
					{
						editable.insert(selStart, "<u>");
						editable.insert(selEnd + 3 , "</u>");
					}
					break;

				}
			}
		};
		btnGras.setOnClickListener(onClickBalise);
		btnItalique.setOnClickListener(onClickBalise);
		btnSouligne.setOnClickListener(onClickBalise);	
		btnSmileySourire.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
//				editText.setText("test <b>gras</b> <i>italique</i> <u>souligne</u>" );
				int cursorIndex = editText.getSelectionStart();
				editText.getText().insert(cursorIndex, "<img src=\"sourire\" >" );
			}
		});
		
		btnSmileyGrosSourire.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				int cursorIndex = editText.getSelectionStart();
				editText.getText().insert(cursorIndex, "<img src=\"grosSourire\" >" );

			}
		});
		
		btnSmileyClinDOeil.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				int cursorIndex = editText.getSelectionStart();
				editText.getText().insert(cursorIndex, "<img src=\"clin\" >" );

			}
		});
		
		editText.addTextChangedListener(new TextWatcher() {
			@Override
			/**
			 * s est la chaîne de caractères qui est en train de changer
			 */
			public void onTextChanged(CharSequence s, int start, int before, int count) {
				// Que faire au moment où le texte change ?
				resultText.setText(Html.fromHtml("<font color =\"" + currentColor + "\">" + s.toString() + "<font>", getter, null));
			}
			@Override
			/**
			 * @param s La chaîne qui a été modifiée
			 * @param count Le nombre de caractères concernés
			 * @param start L'endroit où commence la modification dans la chaîne
			 * @param after La nouvelle taille du texte
			 */
			public void beforeTextChanged(CharSequence s, int start, int count, int after) {
				// Que faire juste avant que le changement de texte soit pris en compte ?
			}
			@Override
			/**
			 * @param s L'endroit où le changement a été effectué
			 */
			public void afterTextChanged(Editable s) {
				// Que faire juste après que le changement de texte a été pris en compte ?              
			}
		});
		
		colorChooser.setOnCheckedChangeListener(new OnCheckedChangeListener() {

			@Override
			public void onCheckedChanged(RadioGroup group, int checkedId) {
				// TODO Auto-generated method stub
				switch(checkedId)
				{
				case R.id.rbtn_noir:
					currentColor = "#000000";
					break;
				case R.id.rbtn_bleu:
					currentColor = "#0022FF";
					break;
				case R.id.rbtn_rouge:
					currentColor = "#FF0000";
					break;

				}
				editText.setText(editText.getText().toString());
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
}
