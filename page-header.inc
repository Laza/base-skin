<%
	if (pageType.equals("index"))
		initIndex();
	else if (pageType.equals("slide"))
		initSlide();
	else
		initPage();
%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="content-type" content="text/html; charset=$textEncoding">
<title>${title}</title>
<ja:if exists="description"><meta name="Description" content="<%= cleanup(description) %>"></ja:if>
<link rel="shortcut icon" href="$resPath/favicon.ico">
<link href="$resPath/common.css" rel="stylesheet" type="text/css">
<link href="$stylePath" rel="stylesheet" type="text/css">
</head>
<body id="${pageType}">

	<%-- Include header.inc from image directory if present --%>
	<ja:include page="header.inc" />
	
	<div id="main">
		
		<%-- Header content from the GUI --%>
		<ja:if exists="headerContent">${headerContent}</ja:if>
		
		<%-- Top navigation :: only if there are pages or folders --%>
		<ja:if test="<%= showTopNavigation && !isEmpty(topNavigation) %>">
		<div id="navigation">
			<%-- The logo --%>
			<ja:if exists="logo">
			<div class="logo"><a href="${rootPath}/${pageName}" title="$text.home"><img src="${resPath}/${logo}" alt="${albumName}"></a></div>
			</ja:if>
			<%-- Main menu --%>
			<ja:if exists="topNavigation">
			<div class="top-nav<ja:if exists="logo"> with-logo</ja:if>">
				${topNavigation}
			</div>
			</ja:if>
		</div>
		</ja:if>

		<%-- Page header --%>
		<div id="header">

	<ja:switch test="${pageType}">

		<ja:case value="index">
			<%-- Link to parent index (if any) or the user specified up link page --%>
			<ja:if exists="uplink">
			<div class="fleft"><a href="${uplink}" class="navigation" id="up" title=<ja:if exists="parentIndexPage">"$text.up"</ja:if><ja:else>"$text.home" target="_parent"</ja:else>>&nbsp;</a></div>
			</ja:if>
			
			<%-- Create navigation buttons if there´s more than one index page --%>
			<ja:if exists="totalIndexes">
			<div class="fright">
			
				<%-- Previous button --%>
				<ja:if exists="previousIndexPage"><a href="${previousIndexPage}" class="navigation" id="prev" title="$text.previousPage">&nbsp;</a></ja:if>
				<ja:else><span class="navigation" id="prev" title="$text.atFirstPage">&nbsp;</span></ja:else>
				
				<%-- Next button --%>
				<ja:if exists="nextIndexPage"><a href="${nextIndexPage}" class="navigation" id="next" title="$text.nextPage">&nbsp;</a></ja:if>
				<ja:else><span class="navigation" id="next" title="$text.atLastPage">&nbsp;</span></ja:else>
			</div>
			</ja:if>
			
			<%-- Page title --%>
			<div class="headln">
				<h1><ja:if exists="indexBreadcrumbPath"><small>${indexBreadcrumbPath}${pathSep}</small></ja:if><%= title.replaceAll("_", " ") %></h1>
				<ja:if exists="comment"><h5>${comment}</h5></ja:if>
			</div>		
		</ja:case>
	
		<ja:case value="slide">
			<%-- Link to index page --%>
			<div class="fleft"><a href="../${indexPage}" class="navigation" id="up" title="$text.up">&nbsp;</a></div>
			
			<%-- Create navigation buttons if more than one image --%>
			<ja:if test="<%= totalImages != void && totalImages > 1 %>">
			<div class="fright">
			
				<%-- Previous button --%>
				<ja:if exists="previousPage"><a href="${previousPage}" class="navigation" id="prev" title="$text.previousPage">&nbsp;</a></ja:if>
				<ja:else><span class="navigation" id="prev" title="$text.atFirstPage">&nbsp;</span></ja:else>
				
				<%-- Next button --%>
				<ja:if exists="nextPage"><a href="${nextPage}" class="navigation" id="next" title="$text.nextPage">&nbsp;</a></ja:if>
				<ja:else><span class="navigation" id="next" title="$text.atLastPage">&nbsp;</span></ja:else>
			</div>
			</ja:if>
			
			<%-- Page title --%>
			<div class="headln">
				<h1><ja:if exists="slideBreadcrumbPath"><small>${slideBreadcrumbPath}${pathSep}</small></ja:if><%= title.replaceAll("_", " ") %></h1>
			</div>
		</ja:case>
	
		<ja:default>
			<ja:if exists="uplink"><div class="fleft"><a href="${uplink}" class="navigation" id="up" title="$text.up">&nbsp;</a></div></ja:if>
			
			<div class="headln">
				<h1><ja:if exists="indexBreadcrumbPath"><small>${pageBreadcrumbPath}${pathSep}</small></ja:if><%= title.replaceAll("_", " ") %></h1>
			</div>
		</ja:default>

	</ja:switch>
	
		</div> <%-- #header --%>
		
		<div id="content">

