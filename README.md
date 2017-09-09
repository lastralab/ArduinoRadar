# ArduinoRadar
Radar using Arduino, Ping, Servo and Processing.

The original code belongs to Dejan Nedelkovski, this is an adaptation for Mac users and for my own needs.

THE WIRING:

<img width="989" alt="screenshot 2017-01-31 15 36 43" src="https://cloud.githubusercontent.com/assets/22894897/22487594/3a54d2f8-e7cb-11e6-8dbd-ad94e7cb77a8.png">

CODE for Arduino (fixed):

<pre>
<font color="#434f54">//Original code by Dejan Nedelkovski</font>
<font color="#434f54">//Author: Niam Moltta</font>
<font color="#434f54">//RADAR</font>

<font color="#5e6d03">#include</font> <font color="#434f54">&lt;</font><b><font color="#d35400">Servo</font></b><font color="#434f54">.</font><font color="#000000">h</font><font color="#434f54">&gt;</font><font color="#434f54">.</font> 

<font color="#00979c">const</font> <font color="#00979c">int</font> <font color="#000000">trigPin</font> <font color="#434f54">=</font> <font color="#000000">7</font><font color="#000000">;</font>
<font color="#00979c">const</font> <font color="#00979c">int</font> <font color="#000000">echoPin</font> <font color="#434f54">=</font> <font color="#000000">8</font><font color="#000000">;</font>

<font color="#00979c">long</font> <font color="#000000">duration</font><font color="#000000">;</font>
<font color="#00979c">int</font> <font color="#000000">distance</font><font color="#000000">;</font>
<b><font color="#d35400">Servo</font></b> <font color="#000000">myServo</font><font color="#000000">;</font> 

<font color="#00979c">void</font> <font color="#5e6d03">setup</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;
 &nbsp;<font color="#d35400">pinMode</font><font color="#000000">(</font><font color="#000000">trigPin</font><font color="#434f54">,</font> <font color="#00979c">OUTPUT</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<font color="#d35400">pinMode</font><font color="#000000">(</font><font color="#000000">echoPin</font><font color="#434f54">,</font> <font color="#00979c">INPUT</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">begin</font><font color="#000000">(</font><font color="#000000">9600</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">myServo</font><font color="#434f54">.</font><font color="#d35400">attach</font><font color="#000000">(</font><font color="#000000">9</font><font color="#000000">)</font><font color="#000000">;</font> 
<font color="#000000">}</font>

<font color="#00979c">void</font> <font color="#5e6d03">loop</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font>
 &nbsp;
 &nbsp;<font color="#5e6d03">for</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">i</font><font color="#434f54">=</font><font color="#000000">15</font><font color="#000000">;</font><font color="#000000">i</font><font color="#434f54">&lt;=</font><font color="#000000">165</font><font color="#000000">;</font><font color="#000000">i</font><font color="#434f54">++</font><font color="#000000">)</font><font color="#000000">{</font> &nbsp;
 &nbsp;<font color="#000000">myServo</font><font color="#434f54">.</font><font color="#d35400">write</font><font color="#000000">(</font><font color="#000000">i</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">30</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">distance</font> <font color="#434f54">=</font> <font color="#000000">calculateDistance</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#000000">i</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#005c5f">","</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#000000">distance</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#005c5f">"."</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<font color="#000000">}</font>
 &nbsp;
 &nbsp;<font color="#5e6d03">for</font><font color="#000000">(</font><font color="#00979c">int</font> <font color="#000000">i</font><font color="#434f54">=</font><font color="#000000">165</font><font color="#000000">;</font><font color="#000000">i</font><font color="#434f54">&gt;</font><font color="#000000">15</font><font color="#000000">;</font><font color="#000000">i</font><font color="#434f54">--</font><font color="#000000">)</font><font color="#000000">{</font> &nbsp;
 &nbsp;<font color="#000000">myServo</font><font color="#434f54">.</font><font color="#d35400">write</font><font color="#000000">(</font><font color="#000000">i</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">30</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;
 &nbsp;<font color="#000000">distance</font> <font color="#434f54">=</font> <font color="#000000">calculateDistance</font><font color="#000000">(</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#000000">i</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#005c5f">","</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#000000">distance</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<b><font color="#d35400">Serial</font></b><font color="#434f54">.</font><font color="#d35400">print</font><font color="#000000">(</font><font color="#005c5f">"."</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">}</font>
<font color="#000000">}</font>

<font color="#00979c">int</font> <font color="#000000">calculateDistance</font><font color="#000000">(</font><font color="#000000">)</font> <font color="#000000">{</font> 
 &nbsp;
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">trigPin</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<font color="#d35400">delayMicroseconds</font><font color="#000000">(</font><font color="#000000">2</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">trigPin</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<font color="#d35400">delayMicroseconds</font><font color="#000000">(</font><font color="#000000">10</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">trigPin</font><font color="#434f54">,</font> <font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;<font color="#000000">duration</font> <font color="#434f54">=</font> <font color="#d35400">pulseIn</font><font color="#000000">(</font><font color="#000000">echoPin</font><font color="#434f54">,</font> <font color="#00979c">HIGH</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;<font color="#000000">distance</font><font color="#434f54">=</font> <font color="#000000">duration</font><font color="#434f54">*</font><font color="#000000">0.034</font><font color="#434f54">/</font><font color="#000000">2</font><font color="#000000">;</font>
 &nbsp;<font color="#5e6d03">return</font> <font color="#000000">distance</font><font color="#000000">;</font>
<font color="#000000">}</font>

</pre>

CODE for Processing:

<html><body><pre>
<span style="color: #666666;">//For&nbsp;Processing&nbsp;3.2.3-&nbsp;MacOS&nbsp;Sierra</span>
<span style="color: #666666;">//Author:&nbsp;Niam&nbsp;Moltta</span>
<span style="color: #666666;">//Jan-2017</span>

<span style="color: #33997E;">import</span> processing.serial.*; <span style="color: #666666;">// imports library for serial communication</span>
<span style="color: #33997E;">import</span> java.awt.event.KeyEvent; <span style="color: #666666;">// imports library for reading the data from the serial port</span>
<span style="color: #33997E;">import</span> java.io.IOException;

<span style="color: #E2661A;">String</span> Port = <span style="color: #7D4793;">&quot;/dev/tty.usbmodem1411&quot;</span>; <span style="color: #666666;">//Arduino port</span>
Serial&nbsp;myPort;&nbsp;

<span style="color: #E2661A;">String</span> angle=<span style="color: #7D4793;">&quot;&quot;</span>;
<span style="color: #E2661A;">String</span> distance=<span style="color: #7D4793;">&quot;&quot;</span>;
<span style="color: #E2661A;">String</span> data=<span style="color: #7D4793;">&quot;&quot;</span>;
<span style="color: #E2661A;">String</span> noObject;
<span style="color: #E2661A;">float</span> pixsDistance;
<span style="color: #E2661A;">int</span> iAngle, iDistance;
<span style="color: #E2661A;">int</span> index1=0;
<span style="color: #E2661A;">int</span> index2=0;
<span style="color: #E2661A;">PFont</span> orcFont;

<span style="color: #33997E;">void</span> <span style="color: #006699;"><b>setup</b></span>() {
&nbsp;&nbsp;
&nbsp;<span style="color: #006699;">size</span> (1250, 650); <span style="color: #666666;">//resolution</span>
&nbsp;<span style="color: #006699;">smooth</span>();
&nbsp;myPort&nbsp;=&nbsp;<span style="color: #33997E;">new</span> Serial(<span style="color: #33997E;">this</span>, Port, 9600); 
&nbsp;myPort.bufferUntil(<span style="color: #7D4793;">&apos;.&apos;</span>); 
&nbsp;orcFont&nbsp;=&nbsp;<span style="color: #006699;">loadFont</span>(<span style="color: #7D4793;">&quot;OCRAExtended-30.vlw&quot;</span>);
}
<span style="color: #33997E;">void</span> <span style="color: #006699;"><b>draw</b></span>() {
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #006699;">fill</span>(98,245,31);
&nbsp;&nbsp;<span style="color: #006699;">textFont</span>(orcFont);
&nbsp;&nbsp;<span style="color: #006699;">noStroke</span>();
&nbsp;&nbsp;<span style="color: #006699;">fill</span>(0,4); 
&nbsp;&nbsp;<span style="color: #006699;">rect</span>(0, 0, <span style="color: #D94A7A;">width</span>, <span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.065); 
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #006699;">fill</span>(98,245,31); 
&nbsp;&nbsp;
&nbsp;&nbsp;drawRadar();&nbsp;
&nbsp;&nbsp;drawLine();
&nbsp;&nbsp;drawObject();
&nbsp;&nbsp;drawText();
}

<span style="color: #33997E;">void</span> serialEvent (Serial myPort) { 
&nbsp;&nbsp;
&nbsp;&nbsp;data&nbsp;=&nbsp;myPort.readStringUntil(<span style="color: #7D4793;">&apos;.&apos;</span>);
&nbsp;&nbsp;data&nbsp;=&nbsp;data.<span style="color: #006699;">substring</span>(0,data.<span style="color: #006699;">length</span>()-1);
&nbsp;&nbsp;
&nbsp;&nbsp;index1&nbsp;=&nbsp;data.<span style="color: #006699;">indexOf</span>(<span style="color: #7D4793;">&quot;,&quot;</span>); 
&nbsp;&nbsp;angle=&nbsp;data.<span style="color: #006699;">substring</span>(0, index1); 
&nbsp;&nbsp;distance=&nbsp;data.<span style="color: #006699;">substring</span>(index1+1, data.<span style="color: #006699;">length</span>()); 
&nbsp;&nbsp;
&nbsp;&nbsp;iAngle&nbsp;=&nbsp;<span style="color: #006699;">int</span>(angle);
&nbsp;&nbsp;iDistance&nbsp;=&nbsp;<span style="color: #006699;">int</span>(distance);
}
<span style="color: #33997E;">void</span> drawRadar() {
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #006699;">pushMatrix</span>();
&nbsp;&nbsp;<span style="color: #006699;">translate</span>(<span style="color: #D94A7A;">width</span>/2,<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.074); 
&nbsp;&nbsp;<span style="color: #006699;">noFill</span>();
&nbsp;&nbsp;<span style="color: #006699;">strokeWeight</span>(2);
&nbsp;&nbsp;<span style="color: #006699;">stroke</span>(98,245,31);
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #006699;">arc</span>(0,0,(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.0625),(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.0625),<span style="color: #718A62;">PI</span>,<span style="color: #718A62;">TWO_PI</span>);
&nbsp;&nbsp;<span style="color: #006699;">arc</span>(0,0,(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.27),(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.27),<span style="color: #718A62;">PI</span>,<span style="color: #718A62;">TWO_PI</span>);
&nbsp;&nbsp;<span style="color: #006699;">arc</span>(0,0,(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.479),(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.479),<span style="color: #718A62;">PI</span>,<span style="color: #718A62;">TWO_PI</span>);
&nbsp;&nbsp;<span style="color: #006699;">arc</span>(0,0,(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.687),(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.687),<span style="color: #718A62;">PI</span>,<span style="color: #718A62;">TWO_PI</span>);
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #006699;">line</span>(-<span style="color: #D94A7A;">width</span>/2,0,<span style="color: #D94A7A;">width</span>/2,0);
&nbsp;&nbsp;<span style="color: #006699;">line</span>(0,0,(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(30)),(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(30)));
&nbsp;&nbsp;<span style="color: #006699;">line</span>(0,0,(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(60)),(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(60)));
&nbsp;&nbsp;<span style="color: #006699;">line</span>(0,0,(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(90)),(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(90)));
&nbsp;&nbsp;<span style="color: #006699;">line</span>(0,0,(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(120)),(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(120)));
&nbsp;&nbsp;<span style="color: #006699;">line</span>(0,0,(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(150)),(-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(150)));
&nbsp;&nbsp;<span style="color: #006699;">line</span>((-<span style="color: #D94A7A;">width</span>/2)*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(30)),0,<span style="color: #D94A7A;">width</span>/2,0);
&nbsp;&nbsp;<span style="color: #006699;">popMatrix</span>();
}

<span style="color: #33997E;">void</span> drawObject() {
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #006699;">pushMatrix</span>();
&nbsp;&nbsp;<span style="color: #006699;">translate</span>(<span style="color: #D94A7A;">width</span>/2,<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.074); 
&nbsp;&nbsp;<span style="color: #006699;">strokeWeight</span>(9);
&nbsp;&nbsp;<span style="color: #006699;">stroke</span>(255,10,10); 
&nbsp;&nbsp;pixsDistance&nbsp;=&nbsp;iDistance*((<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.1666)*0.025); 
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #669900;">if</span>(iDistance&lt;40){ <span style="color: #666666;">//range limit</span>
&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #006699;">line</span>(pixsDistance*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(iAngle)),-pixsDistance*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(iAngle)),(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.505)*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(iAngle)),-(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.505)*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(iAngle)));
&nbsp;&nbsp;}
&nbsp;&nbsp;<span style="color: #006699;">popMatrix</span>();
}
<span style="color: #33997E;">void</span> drawLine() {
&nbsp;&nbsp;<span style="color: #006699;">pushMatrix</span>();
&nbsp;&nbsp;<span style="color: #006699;">strokeWeight</span>(9);
&nbsp;&nbsp;<span style="color: #006699;">stroke</span>(30,250,60);
&nbsp;&nbsp;<span style="color: #006699;">translate</span>(<span style="color: #D94A7A;">width</span>/2,<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.074); 
&nbsp;&nbsp;<span style="color: #006699;">line</span>(0,0,(<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.12)*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(iAngle)),-(<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.12)*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(iAngle))); 
&nbsp;&nbsp;<span style="color: #006699;">popMatrix</span>();
}

<span style="color: #33997E;">void</span> drawText() { 
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #006699;">pushMatrix</span>();
&nbsp;&nbsp;<span style="color: #006699;">fill</span>(0,0,0);
&nbsp;&nbsp;<span style="color: #006699;">noStroke</span>();
&nbsp;&nbsp;<span style="color: #006699;">rect</span>(0, <span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0648, <span style="color: #D94A7A;">width</span>, <span style="color: #D94A7A;">height</span>);
&nbsp;&nbsp;<span style="color: #006699;">fill</span>(98,245,31);
&nbsp;&nbsp;<span style="color: #006699;">textSize</span>(15);
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;10cm&quot;</span>,<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.3854,<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0833);
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;20cm&quot;</span>,<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.281,<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0833);
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;30cm&quot;</span>,<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.177,<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0833);
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;40cm&quot;</span>,<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.0729,<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0833);
&nbsp;&nbsp;<span style="color: #006699;">textSize</span>(30);
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;Angle: &quot;</span> + iAngle +<span style="color: #7D4793;">&quot; &#176;&quot;</span>, <span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.48, <span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0277);
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;Distance: &quot;</span>, <span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.26, <span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0277);
&nbsp;&nbsp;<span style="color: #669900;">if</span>(iDistance&lt;40) {
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;        &quot;</span> + iDistance +<span style="color: #7D4793;">&quot; cm&quot;</span>, <span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.225, <span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0277);
&nbsp;&nbsp;}
&nbsp;&nbsp;<span style="color: #006699;">textSize</span>(25);
&nbsp;&nbsp;<span style="color: #006699;">fill</span>(98,245,60);
&nbsp;&nbsp;<span style="color: #006699;">translate</span>((<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.4994)+<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(30)),(<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0907)-<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(30)));
&nbsp;&nbsp;<span style="color: #006699;">rotate</span>(-<span style="color: #006699;">radians</span>(-60));
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;30&#176;&quot;</span>,0,0);
&nbsp;&nbsp;<span style="color: #006699;">resetMatrix</span>();
&nbsp;&nbsp;<span style="color: #006699;">translate</span>((<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.503)+<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(60)),(<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0888)-<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(60)));
&nbsp;&nbsp;<span style="color: #006699;">rotate</span>(-<span style="color: #006699;">radians</span>(-30));
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;60&#176;&quot;</span>,0,0);
&nbsp;&nbsp;<span style="color: #006699;">resetMatrix</span>();
&nbsp;&nbsp;<span style="color: #006699;">translate</span>((<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.507)+<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(90)),(<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0833)-<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(90)));
&nbsp;&nbsp;<span style="color: #006699;">rotate</span>(<span style="color: #006699;">radians</span>(0));
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;90&#176;&quot;</span>,0,0);
&nbsp;&nbsp;<span style="color: #006699;">resetMatrix</span>();
&nbsp;&nbsp;<span style="color: #006699;">translate</span>(<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.513+<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(120)),(<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.07129)-<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(120)));
&nbsp;&nbsp;<span style="color: #006699;">rotate</span>(<span style="color: #006699;">radians</span>(-30));
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;120&#176;&quot;</span>,0,0);
&nbsp;&nbsp;<span style="color: #006699;">resetMatrix</span>();
&nbsp;&nbsp;<span style="color: #006699;">translate</span>((<span style="color: #D94A7A;">width</span>-<span style="color: #D94A7A;">width</span>*0.5104)+<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">cos</span>(<span style="color: #006699;">radians</span>(150)),(<span style="color: #D94A7A;">height</span>-<span style="color: #D94A7A;">height</span>*0.0574)-<span style="color: #D94A7A;">width</span>/2*<span style="color: #006699;">sin</span>(<span style="color: #006699;">radians</span>(150)));
&nbsp;&nbsp;<span style="color: #006699;">rotate</span>(<span style="color: #006699;">radians</span>(-60));
&nbsp;&nbsp;<span style="color: #006699;">text</span>(<span style="color: #7D4793;">&quot;150&#176;&quot;</span>,0,0);
&nbsp;&nbsp;<span style="color: #006699;">popMatrix</span>(); 
}

</pre></body></html>

This is how it looks finished (sorry for bad quality of gif):

![rad](https://cloud.githubusercontent.com/assets/22894897/22487906/8b255f26-e7cc-11e6-82bf-299cf0ff6229.gif)
<br>
<br>
<p align="center"><a href="https://lastralab.github.io/website/" target="_blank"><br><button><img src="http://i.imgur.com/ERyS5Xn.png" alt="l'astra lab icon" width="50px" background="transparent" opacity="0.5" padding="0;"/></button></a></p><br><br>
