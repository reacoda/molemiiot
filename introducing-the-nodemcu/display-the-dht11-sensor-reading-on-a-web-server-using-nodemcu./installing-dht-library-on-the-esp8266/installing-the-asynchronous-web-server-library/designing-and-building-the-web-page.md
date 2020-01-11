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



