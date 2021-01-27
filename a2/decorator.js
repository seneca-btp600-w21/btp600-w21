var Label = function(labelText,x,y){
	var that = {};
	var labelText_=labelText || "";
	var x_=x || 200;
	var y_=y || 200;
	var hasBorder_ = false;
	var hasThickRectBorder_= false;
	var hasDots_ = false;
	var width_ = labelText_.length * 10;
	var height_ = 40;


	that.draw = function(){
		if(hasBorder_){
			rectMode(CENTER);
			strokeWeight(1);
			stroke(0,0,0);
			noFill();
			rect(x_,y_,width_,height_);			
		}
		if(hasThickRectBorder_){
			rectMode(CENTER);
			strokeWeight(3);
			stroke(0,0,0);
			noFill();
			rect(x_,y_,width_,height_);						
		}
		if (hasDots_){
			ellipseMode(CENTER);
			strokeWeight(1);
			fill(255,0,0);
			stroke(255,0,0);
			//above label
			for(var i=0;i<width_/10 + 1;i++){
				ellipse((x_-width_/2+i*10),(y_-height_/2),5,5);
			}
			//below label
			for(var i=0;i<width_/10 +1;i++){
				ellipse((x_-width_/2+i*10),(y_+height_/2),5,5);
			}
			//left of label
			for(var i=0;i<height_/10-1;i++){
				ellipse((x_-width_/2),(y_-height_/2+((i+1)*10)),5,5);
			}
			//right of label
			for(var i=0;i<height_/10-1;i++){
				ellipse((x_+width_/2),(y_-height_/2+((i+1)*10)),5,5);
			}
		}
		strokeWeight(1);
		stroke(0,0,0);
		fill(0,0,0);
		textAlign(CENTER,CENTER);
		text(labelText_,x_,y_);

	}
	that.toggleThinBorder = function(){
		if (hasBorder_==true){
			hasBorder_=false;
		}
		else{
			hasBorder_=true;
		}
	}
	that.toggleThickBorder = function(){
		if (hasThickRectBorder_==true){
			hasThickRectBorder_=false;
		}
		else{
			hasThickRectBorder_=true;
		}
	}
	that.toggleDots = function(){
		if (hasDots_==true){
			hasDots_=false;
		}
		else{
			hasDots_=true;
		}
	}

	return that;
};

var labels=[];
var thickBorderButton;
var borderButton;
var dotButton;
var removeButton;
var selectLabelRadio;
var selected;
var numLabels;

/*
  these four functions are called when button is pressed
  modify the "add" functions to apply decorator to the 
  selected label.   
*/
function addThinBorder(){
	labels[selected].toggleThinBorder();
}
function addThick(){
	labels[selected].toggleThickBorder();
}
function addDots(){
	labels[selected].toggleDots();
}

/*
  Challenge: removeLastBorder function.  If you add this feature
  use this function to remove the most recent decorator 
  from the selected label
 */
function removeLastBorder(){

}


/*********************************************************/
/* NOTHING BELOW THIS COMMENT IS TO BE MODIFIED          */
/*********************************************************/

function setup(){
	createCanvas(600,500);	

    thickBorderButton=createButton("Add Thick Border");
    thickBorderButton.mousePressed(addThick);
    thickBorderButton.position(10,550);
    borderButton=createButton("Add Thin Border");
    borderButton.mousePressed(addThinBorder);
    borderButton.position(160,550);
    dotButton=createButton("Add Dots Border");
    dotButton.mousePressed(addDots);
    dotButton.position(310,550);

    removeButton=createButton("Remove Last");
    removeButton.mousePressed(removeLastBorder);
    removeButton.position(460,550);

	selectLabelRadio=createRadio();
	numLabels=5;
	for(var i=0;i<numLabels;i++){
		selectLabelRadio.option(""+i,"Label "+(i+1));
		labels[i] = Label("Label "+(i+1), random(50,550), random(20,480));
	}
    selectLabelRadio.selected(0);

}


/* This function is not to be modified*/
function draw(){
	selected=selectLabelRadio.value();
	background(255,255,255);
	for(var i=0;i<numLabels;i++){
		labels[i].draw();
	}
}
	