# Designing and building the web page

In order to build the web page we will store all the HTML text and CSS styles in the index\_html variable in the Arduino code.

Open the Arduino IDE and declare the index\_html variable as follows:

```text
const char index_html[] PROGMEM = R"rawliteral( )
```

Add the &lt;meta&gt; tag. This is important as it is used to make your web page responsive:

```text
<meta name="viewport" content="width=device-width, initial-scale=1">
```

The  tag is needed to load the icons from the fontawesome website.

```text
<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
```

#### Styles:

Between the  tags, we add some CSS to style the web page.

```text
<style>
 html {
   font-family: Arial;
   display: inline-block;
   margin: 0px auto;
   text-align: center;
  }
  h2 { font-size: 3.0rem; }
  p { font-size: 3.0rem; }
  .units { font-size: 1.2rem; }
  .ds-labels{
    font-size: 1.5rem;
    vertical-align:middle;
    padding-bottom: 15px;
  }
</style>
```

We are setting the HTML page to be written in Arial font with block without margin and aligned to the center:

```text
html {
  font-family: Arial;
  display: inline-block;
  margin: 0px auto;
  text-align: center;
}
```

We set the font size for the heading \(h2\), paragraph \(p\) and the units\(.units\) of the readings.



```text
h2 { font-size: 3.0rem; }
p { font-size: 3.0rem; }
.units { font-size: 1.2rem; }
```

All of the previous tags should go between the  and tags. These tags are used to include content that is not directly visible to the user, like the  , the  tags, and the styles.

The labels for the readings are styled as shown below:

```text
ds-labels{
  font-size: 1.5rem;
  vertical-align:middle;
  padding-bottom: 15px;
}
```

#### HTML Body 

Inside the &lt;body&gt;&lt;/body&gt; tags is where we add the web page content.  
The &lt;h2&gt;&lt;/h2&gt; tags add a heading to the web page. In this case, the “ESP DS18B20 server” text, but you can add any other text.

Then we add the two paragraphs. One is for the temperature in celsius while the other is in Fahrenheit. The paragraphs are delimited by the  and tags.

**Temperature in Celsius**

```text
 <p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="ds-labels">Temperature Celsius</span> 
    <span id="temperaturec">%TEMPERATUREC%</span>
    <sup class="units">&deg;C</sup>
  </p>
```

 **Temperature in Fahrenheit**

\*\*\*\*

```text
<p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="ds-labels">Temperature Fahrenheit</span>
    <span id="temperaturef">%TEMPERATUREF%</span>
    <sup class="units">&deg;F</sup>
  </p>
```

The  tags display the fontawesome icons.



