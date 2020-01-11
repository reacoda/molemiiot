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
  .dht-labels{
    font-size: 1.5rem;
    vertical-align:middle;
    padding-bottom: 15px;
  }
</style>
```



