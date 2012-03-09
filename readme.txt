****************************************
*                                      *
*  Read.me - Base skin tweaking guide  *
*                                      *
****************************************

1. What does a skin do in jAlbum?

Skins in jAlbum determine the layout and functionality of the generated album pages. 
They do it by providing template files (.htt - HTml Template) for the HTML files,
CSS file(s) for the styles and graphic files for the design. The processing of the
images (thumbnail generation, scaling, filters, metadata extraction) is done by
the jAlbum application. jAlbum cycles through the folders and images and replaces 
the jAlbum variables in the skin's template files with the actual values. For a
menthal model think of how a cake is done. The images are the ingredients, the skin
is the recipe, the jAlbum application is the oven and the cake is your album.

If you are new to web design here is the basic concept:
- HTML (the page content and logical structure)
- CSS (the look, the visual design)
- JS (the interaction between the user and the page)
If you separate these three properly your page will load faster, complies with standards,
crawled better by search bots and the maintenance will be much easier.

2. The structure of a skin

- index.htt (the thumbnail a.k.a index page HTML template)
- slide.htt (the closeup a.k.a slide page HTML template)
- common.css (the basic style sheet intended to be shared by all styles)
- init.bsh (the Beanshell script that's executed first in the album generation process)
- onload.bsh (the Beanshell script that runs on skin load and creates the user interface)
- page-header.inc (the header part to be included in all pages)
- page-footer.inc (the footer that's attached to every page)
- navigation-bar.inc (the code that compiles the navigation bar if the album is used as a site)
+ includes (folder to store code to be used by the basic skin files :: optional) 
  - util.bsh (collection of utility functions, separated from the actual skin code :: optional)
+ plugins (folder to store Java compiled code for advanced functions)
+ res (folder for all the graphic files required in the generated albums)
+ styles (folder holding the skin's styles)
  - Simple.css (the stylesheet that contains the specific modifications relative to common.css)
  - Simple.jap (the predefined values the style should start with)
  + Simple (folder to hold all the graphic files specific to this style)
+ texts (the translation files for the skin's user interface and the texts used in the albums)
  - texts.properties (the english translation file)
  - texts_xx.properties (translation for 'xx' language, where xx is the 2 letter country code)

Read in detail:
http://jalbum.net/en/developer/skins/organization
  
3. Creating a new style

The easiest way in modifying a skin is changing its style. You will need at least basic
knowledge of CSS. If you'd like to keep the skin's original styles you can simply copy
the style is closest to your idea. I strongly suggest avoid modifying the original styles 
to be able to easily update the skin when a new version comes out. If you plan to modify
a bundled skin (those not in bold in the skin chooser combo box) first off install it
from jAlbum's skin section. This will make sure you start with the latest version, and
installs the skin in your home folder. (The skins came bundled are in the 'Program Files'
folder and thus you cannot easily modify them.)

To copy a style first go to the skin directory (Ctrl-Alt-S from jAlbum) and change to 
'styles' folder. Now create a copy of the chosen style (e.g. Simple) by duplicating 
'Simple.css', 'Simple.jap' and the 'Simple' folder, and renaming to e.g. 'MySimple.css', 
'MySimple.jap' and the 'MySimple' folder respectively. Now you can use jAlbum's built-in 
editor by pressing Ctrl-Shift-E or use your preferred one. (The jAlbum editor gives you 
proper syntax highlighting for jAlbum variables.) 

In the CSS file you can redefine all the styles of common.css. If you'd like to add your 
own graphics, add it the 'MySimple' folder. To redefine the default values of the skin 
use the 'MySimple.jap' file. Once you are content with the new style (and you are a 
prefectionist) take a screenshot of the generated page, crop and save as 'MyStyle.jpg' 
in the styles folder. (a 480px wide will do)

Please note: If you made any modifications to a skin you need to backup, otherwise
all the modifications get overwritten after a skin or software update. To make a backup
you only need to use the 'Tools / Skin developer / Pack as .jaskin file' tool in jAlbum. 
This will save a copy of the skin in zipped format in the root of the jAlbum skins 
folder (use Ctrl-Alt-S to open in explorer). If you want the skin to be restored just 
double click the .jaskin file. If you only need some of the files or folders (e.g. your
custom style), rename the .jaskin file to .zip (ignore the warning), and go into it
by double clicking. Now you can copy your custom style to an updated skin for example.

4. Modifying the HTML structure

This is a bit more advanced topic. You will need basic HTML knowledge, and you also
need to know how jAlbum works. Here's a rough developer guide to jAlbum scripting:
http://jalbum.net/en/developer/skins

If you are modifying a skin deeply you might want to consider renaming the skin,
e.g. to 'MyBase' to avoid conflicts with later skin updates. To do this go to the
skin directory (Ctrl-Alt-S), go up one level, and copy the whole skin folder under 
a new name. 

5. Adding new User Interface elements

The user interface is written in Beanshell sript / Java Swing. Read this tutorial if
you'd like to know more:
http://jalbum.net/en/developer/skins/user-interface


6. Adding pages

Base comes with predefined styles for 2 pages, About and Contact:

About:
<ja:include page="page-header.inc" /> <%-- Keep this --%>

		<div class="about-box">
			<div class="about-photo"><img src="${resPath}/author.jpg" alt="${author}" /></div>
			<div class="about-text">${comment}</div>
			<div class="clear"></div>
		</div>

<ja:include page="page-footer.inc" /> <%-- Keep this --%>

Contact:
<ja:include page="page-header.inc" /> <%-- Keep this --%>

		<div class="contact-box">
			<div class="contact-text">${comment}</div>
		</div>

<ja:include page="page-footer.inc" /> <%-- Keep this --%>

You can Copy/Paste this code to the New Page template.

Good luck, 
Laza

And don't forget there is forum with lot of helpful people to give you hand if you 
happen to stuck:
http://jalbum.net/forum/forum.jspa?forumID=73


