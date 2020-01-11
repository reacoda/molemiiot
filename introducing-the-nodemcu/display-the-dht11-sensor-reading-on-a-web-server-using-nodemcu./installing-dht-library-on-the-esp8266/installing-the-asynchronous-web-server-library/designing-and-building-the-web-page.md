# Designing and building the web page

![](../../../../.gitbook/assets/web-server-labeled.png)

As you can see in the above figure, the web page shows one heading and two paragraphs. There is a paragraph to display the temperature and another to display the humidity. There are also two icons to style the page.

Let’s see how this web page is created.

All the HTML text with styles included is stored in the index\_html variable. Now we’ll go through the HTML text and see what each part does.

The following &lt;meta&gt; tag makes your web page responsive in any browser.

```text
<meta name="viewport" content="width=device-width, initial-scale=1">
```

The &lt;link&gt; tag is needed to load the icons from the fontawesome website.

```text
<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384
```

**Styles**

Between the &lt;style&gt;&lt;/style&gt; tags, we add some CSS to style the web page.

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
  .dht-labels{
    font-size: 1.5rem;
    vertical-align:middle;
    padding-bottom: 15px;
  }
</style>
```

Basically, we’re setting the HTML page to display the text with Arial font in block without margin, and aligned at the center.

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

The labels for the readings are styled as shown below:

```text
dht-labels{
  font-size: 1.5rem;
  vertical-align:middle;
  padding-bottom: 15px;
}
```

All of the previous tags should go between the &lt;head&gt; and &lt;/head&gt; tags. These tags are used to include content that is not directly visible to the user, like the &lt;meta&gt; , the &lt;link&gt; tags, and the styles.

**HTML Body**

Inside the &lt;body&gt;&lt;/body&gt; tags is where we add the web page content.  


The &lt;h2&gt;&lt;/h2&gt; tags add a heading to the web page. In this case, the “ESP8266 DHT server” text, but you can add any other text.  


```text
<h2>ESP8266 DHT Server</h2>
```

Then, there are two paragraphs. One to display the temperature and the other to display the humidity. The paragraphs are delimited by the &lt;p&gt; and &lt;/p&gt; tags. The paragraph for the temperature is the following:

```text
<p>
  <i class="fas fa-thermometer-half" style="color:#059e8a;"</i> 
  <span class="dht-labels">Temperature</span> 
  <span id="temperature">%TEMPERATURE%</span>
  <sup class="units">°C</sup>
</p>
```

And the paragraph for the humidity is on the following snipet:

```text
<p>
  <i class="fas fa-tint" style="color:#00add6;"></i> 
  <span class="dht-labels">Humidity</span>
  <span id="humidity">%HUMIDITY%</span>
  <sup class="units">%</sup>
</p>
```

The &lt;i&gt; tags display the fontawesome icons.

**How to display icons**

To chose the icons, go to the [Font Awesome Icons website](https://fontawesome.com/icons?d=gallery).  


![FontAwesome Home Page \(randomnerdtutorial.com\)](../../../../.gitbook/assets/fontawesomepage.png)

Search the icon you’re looking for. For example, “thermometer”:

![](../../../../.gitbook/assets/fontawesome-thermometer.png)



