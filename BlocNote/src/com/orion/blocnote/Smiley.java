package com.orion.blocnote;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.drawable.Drawable;
import android.text.Html.ImageGetter;

public class Smiley implements ImageGetter {

	protected Context context = null;
	
	public Smiley(Context context) {
		// TODO Auto-generated constructor stub
		this.context = context;
		
	}
	
	@Override
	public Drawable getDrawable(String source) {
		// TODO Auto-generated method stub
		Drawable retour = null;
	    
	    Resources resources = context.getResources();
	    
	    if(source.equals("sourire"))
	    {
	    	retour = resources.getDrawable(R.drawable.smiley_sourire);
	    }
	    else if(source.equals("grosSourire"))
	    {
	    	retour = resources.getDrawable(R.drawable.smiley_gros_sourire);
	    }
	    else
	    {
	    	retour = resources.getDrawable(R.drawable.smiley_clin_oeil);
	    }
	    
	    
	        
	    // On délimite l'image (elle va de son coin en haut à gauche à son coin en bas à droite)
	    retour.setBounds(0, 0, retour.getIntrinsicWidth(), retour.getIntrinsicHeight());
	    return retour;
	}

}
