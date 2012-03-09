<%-- Page footer --%>

		</div> <%-- #page-content --%>

		<%-- Footer content from the GUI --%>
		<ja:if exists="footerContent">${footerContent}</ja:if>
		
		<div id="footer">
			<ja:if test="<%= !isEmpty(bottomNavigation) || !excludeBacklinks %>">
			<div class="bottom-nav">
				<ja:if test="${bottomNavigation}" not value="">${bottomNavigation}</ja:if>
				<ja:if test="<%= !isEmpty(bottomNavigation) && !excludeBacklinks %>"> &nbsp;|&nbsp; </ja:if>
				<ja:if not test="${excludeBacklinks}">$text.madeWith <a href="${generatorUrl}" title="${generator} - $text.jalbumDescription">jAlbum</a> & <a href="http://jalbum.net/skins/skin/${skin}" title="${skin} ${skinVersion} :: ${styleName}">${skin} skin</a></ja:if>
			</div>
			</ja:if>
		</div>

	</div> <%-- #main --%> 
	
	<%-- Include footer.inc from image directory if present --%>
	<ja:include page="footer.inc" />
</body>
</html>
