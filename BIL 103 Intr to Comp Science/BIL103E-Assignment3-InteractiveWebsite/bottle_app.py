from bottle import route, run, default_app, debug, request

def htmlify(title, content):
    page = """<!DOCTYPE html>
              <html>
                  <head>
                      <title>""" + title + """</title>
                      <meta charset="utf-8" />
                      <style>
body {margin-left:500px; background-color:#ccccff; font-family: Condiment; color:black; width:700px;}
table,td {background-color:#ffff99; border:3px solid black; border-collapse:collapse;}
th {background-color:#ff9900; border:3px solid black; font-weight: bold; border-collapse:collapse;}
p {color:black; font-weight:bold; border-radius:7px;}
li, ul {color:white; border-radius:7px; background-color:#9933ff;}
</style>
                  </head>
                  <body>
                      """ + content + """
                  </body>
              </html>"""
    return page

login_list = [["gurkann", "kul"],["erdi", "kandemir"]]
a3_list = [{'Name' : 'Eddard', 'House' : 'Stark', 'Rating' : 4.0, 'Votes' : 3}, {'Name' : 'Theon', 'House' : 'Greyjoy', 'Rating' : 3.0, 'Votes' : 6}, {'Name' : 'Cercei', 'House' : 'Lannister', 'Rating' : 1.5, 'Votes' : 2}]
dead_score = [{'Namek':'jon_snow','Score':0},{'Namek':'daenrys_targaryen','Score':0},{'Namek':'tyrion_lannister','Score':0},{'Namek':'arya_stark','Score':0},{'Namek':'sansa_stark','Score':0},{'Namek':'cercei_lannister','Score':0},{'Namek':'jaime_lannister','Score':0}]


def checkbox_list():
	i=0
	html="<table>\n"
	html+="<tr>\n<th>Name</th>\n<th>House</th>\n<th>Rating</th>\n<th>Votes</th>\n<th>Badassness Level</th>\n</tr>\n"
	for row in a3_list:
		html+="<tr>\n"
		html+="<td>"
		html+=row['Name']
		html+="</td>"
		html+="<td>"
		html+=row['House']
		html+="</td>"
		html+="<td>"
		html+=str(row['Rating'])
		html+="</td>"
		html+="<td>"
		html+=str(row['Votes'])
		html+="</td>\n"
		html+="<td>"
		html+="""<form action="./vote" method="post">"""
		html+="""<input type="radio" name="rate" value="1_"""+str(i)+""""> 1 """
		html+="""<input type="radio" name="rate" value="2_"""+str(i)+""""> 2 """
		html+="""<input type="radio" name="rate" value="3_"""+str(i)+""""> 3 """
		html+="""<input type="radio" name="rate" value="4_"""+str(i)+""""> 4 """
		html+="""<input type="radio" name="rate" value="5_"""+str(i)+""""> 5 """
		html+="</td>"
		html+="</tr>\n"
		i+=1
	html+="</table>"
	html+="""<input type="submit" value="Vote"></form>"""
	html+="""<form action="./add" method="get">
Name&nbsp; : <input type="text" name="Name"><br>
House :  <select name="House">
  <option value="Stark">Stark</option>
  <option value="Targaryen">Targaryen</option>
  <option value="Lennister">Lennister</option>
  <option value="Greyjoy">Greyjoy</option>
  <option value="Baratheon">Baratheon</option>
  <option value="Tyrell">Tyrell</option>
  <option value="Bolton">Bolton</option>
  <option value="Martell">Martell</option>
  <option value="Martell">Martell</option>
  <option value="Other">Other</option>
</select><br>
<input type="submit" value="Add"></form>"""
	html+="<p>Who do you think will die next season?</p>"
	html+="""
	<form action="./checking" method="post">
	<input type="checkbox" name="jon_snow" value="dead"> Jon Snow<br>
	<input type="checkbox" name="daenrys_targaryen" value="dead"> Daenarys Targaryen<br>
	<input type="checkbox" name="tyrion_lannister" value="dead"> Tyrion Lannister<br>
	<input type="checkbox" name="arya_stark" value="dead"> Arya Stark<br>
	<input type="checkbox" name="sansa_stark" value="dead"> Sansa Stark<br>
	<input type="checkbox" name="cercei_lannister" value="dead"> Cercei Lannister<br>
	<input type="checkbox" name="jaime_lannister" value="dead"> Jaime Lannister<br>
	<input type="submit" value="Vote It!">
	</form>
	"""

	kill_list('jon_snow', request.POST.get('jon_snow'))
	kill_list('daenrys_targaryen', request.POST.get('daenrys_targaryen'))
	kill_list('tyrion_lannister', request.POST.get('tyrion_lannister'))
	kill_list('arya_stark', request.POST.get('arya_stark'))
	kill_list('sansa_stark', request.POST.get('sansa_stark'))
	kill_list('cercei_lannister', request.POST.get('cercei_lannister'))
	kill_list('jaime_lannister', request.POST.get('jaime_lannister'))
	html+="<table>"
	html+="<tr><th>Character</th><th>Total Score</th></tr>"
	html+="<tr><td>Jon Snow</th><th>"+str(dead_score[0]['Score'])+"</td></tr>"
	html+="<tr><td>Daenarys Targaryen</th><th>"+str(dead_score[1]['Score'])+"</td></tr>"
	html+="<tr><td>Tyrion Lannister</th><th>"+str(dead_score[2]['Score'])+"</td></tr>"
	html+="<tr><td>Arya Stark</th><th>"+str(dead_score[3]['Score'])+"</td></tr>"
	html+="<tr><td>Sansa Stark</th><th>"+str(dead_score[4]['Score'])+"</td></tr>"
	html+="<tr><td>Cercei Lannister</th><th>"+str(dead_score[5]['Score'])+"</td></tr>"
	html+="<tr><td>Jaime Lannister</th><th>"+str(dead_score[6]['Score'])+"</td></tr></table>"

	return htmlify('Welcome', html)
def kill_list(kill_name, value):
	global dead_score
	for row in dead_score:
		if row['Namek']==kill_name:
			if value=='dead':
				row['Score']+=1
	return

def a3_vote():
	global a3_list
	i=0
	try:
		rate_value=request.POST.get('rate')
		point= int(rate_value[0])
		row_number= int(rate_value[2])
		allrating=0.0
		allrating=float(a3_list[row_number]['Votes'])*float(a3_list[row_number]['Rating'])+float(point)
		a3_list[row_number]['Votes']+=1
		a3_list[row_number]['Rating']=round(allrating/float(a3_list[row_number]["Votes"]),2)

		html="<table>\n"
		html+="<tr>\n<th>Name</th>\n<th>House</th>\n<th>Rating</th>\n<th>Votes</th>\n<th>Badassness Level</th>\n</tr>\n"
		for row in a3_list:
			html+="<tr>\n"
			html+="<td>"
			html+=row['Name']
			html+="</td>"
			html+="<td>"
			html+=row['House']
			html+="</td>"
			html+="<td>"
			html+=str(row['Rating'])
			html+="</td>"
			html+="<td>"
			html+=str(row['Votes'])
			html+="</td>\n"
			html+="<td>"
			html+="""<form action="./vote" method="post">"""
			html+="""<input type="radio" name="rate" value="1_"""+str(i)+""""> 1 """
			html+="""<input type="radio" name="rate" value="2_"""+str(i)+""""> 2 """
			html+="""<input type="radio" name="rate" value="3_"""+str(i)+""""> 3 """
			html+="""<input type="radio" name="rate" value="4_"""+str(i)+""""> 4 """
			html+="""<input type="radio" name="rate" value="5_"""+str(i)+""""> 5 """
			html+="</td>"
			html+="</tr>\n"
			i+=1
		html+="</table>"
		html+="""<input type="submit" value="Vote"></form>"""
		html+="""<form action="./add" method="get">
	Name&nbsp; : <input type="text" name="Name"><br>
	House :  <select name="House">
	  <option value="Stark">Stark</option>
	  <option value="Targaryen">Targaryen</option>
	  <option value="Lennister">Lennister</option>
	  <option value="Greyjoy">Greyjoy</option>
	  <option value="Baratheon">Baratheon</option>
	  <option value="Tyrell">Tyrell</option>
	  <option value="Bolton">Bolton</option>
	  <option value="Martell">Martell</option>
	  <option value="Martell">Martell</option>
	  <option value="Other">Other</option>
	</select><br>
	<input type="submit" value="Add"></form>"""
		html+="<p>Who do you think will die next season?</p>"
		html+="""
		<form action="./checking" method="post">
		<input type="checkbox" name="jon_snow" value="dead"> Jon Snow<br>
		<input type="checkbox" name="daenrys_targaryen" value="dead"> Daenarys Targaryen<br>
		<input type="checkbox" name="tyrion_lannister" value="dead"> Tyrion Lannister<br>
		<input type="checkbox" name="arya_stark" value="dead"> Arya Stark<br>
		<input type="checkbox" name="sansa_stark" value="dead"> Sansa Stark<br>
		<input type="checkbox" name="cercei_lannister" value="dead"> Cercei Lannister<br>
		<input type="checkbox" name="jaime_lannister" value="dead"> Jaime Lannister<br>
		<input type="submit" value="Vote It!">
		</form>
		"""

		kill_list('jon_snow', request.POST.get('jon_snow'))
		kill_list('daenrys_targaryen', request.POST.get('daenrys_targaryen'))
		kill_list('tyrion_lannister', request.POST.get('tyrion_lannister'))
		kill_list('arya_stark', request.POST.get('arya_stark'))
		kill_list('sansa_stark', request.POST.get('sansa_stark'))
		kill_list('cercei_lannister', request.POST.get('cercei_lannister'))
		kill_list('jaime_lannister', request.POST.get('jaime_lannister'))
		html+="<table>"
		html+="<tr><th>Character</th><th>Total Score</th></tr>"
		html+="<tr><td>Jon Snow</th><th>"+str(dead_score[0]['Score'])+"</td></tr>"
		html+="<tr><td>Daenarys Targaryen</th><th>"+str(dead_score[1]['Score'])+"</td></tr>"
		html+="<tr><td>Tyrion Lannister</th><th>"+str(dead_score[2]['Score'])+"</td></tr>"
		html+="<tr><td>Arya Stark</th><th>"+str(dead_score[3]['Score'])+"</td></tr>"
		html+="<tr><td>Sansa Stark</th><th>"+str(dead_score[4]['Score'])+"</td></tr>"
		html+="<tr><td>Cercei Lannister</th><th>"+str(dead_score[5]['Score'])+"</td></tr>"
		html+="<tr><td>Jaime Lannister</th><th>"+str(dead_score[6]['Score'])+"</td></tr></table>"

		return htmlify('Welcome', html)
	except TypeError:
		html="<h1>You can not vote unless you choose something...</h1>"
		return htmlify('Error', html)
def a3_add():
	global a3_list
	global a3_login
	i=0
	new_name=request.GET.get('Name')
	new_house=request.GET.get('House')
	new={'Name' : new_name, 'House' : new_house, 'Rating' : 0, 'Votes' : 0}
	a3_list.append(new)
	html="<table>\n"
	html+="<tr>\n<th>Name</th>\n<th>House</th>\n<th>Rating</th>\n<th>Votes</th>\n<th>Badassness Level</th>\n</tr>\n"
	for row in a3_list:
		html+="<tr>\n"
		html+="<td>"
		html+=row['Name']
		html+="</td>"
		html+="<td>"
		html+=row['House']
		html+="</td>"
		html+="<td>"
		html+=str(row['Rating'])
		html+="</td>"
		html+="<td>"
		html+=str(row['Votes'])
		html+="</td>\n"
		html+="<td>"
		html+="""<form action="./vote" method="post">"""
		html+="""<input type="radio" name="rate" value="1_"""+str(i)+""""> 1 """
		html+="""<input type="radio" name="rate" value="2_"""+str(i)+""""> 2 """
		html+="""<input type="radio" name="rate" value="3_"""+str(i)+""""> 3 """
		html+="""<input type="radio" name="rate" value="4_"""+str(i)+""""> 4 """
		html+="""<input type="radio" name="rate" value="5_"""+str(i)+""""> 5 """
		html+="</td>"
		html+="</tr>\n"
		i+=1
	html+="</table>"
	html+="""<input type="submit" value="Vote"></form>"""

	html+="""<form action="./add" method="get">
Name&nbsp; : <input type="text" name="Name"><br>
House : <select name="House">
  <option value="Stark">Stark</option>
  <option value="Targaryen">Targaryen</option>
  <option value="Lennister">Lennister</option>
  <option value="Greyjoy">Greyjoy</option>
  <option value="Baratheon">Baratheon</option>
  <option value="Tyrell">Tyrell</option>
  <option value="Bolton">Bolton</option>
  <option value="Martell">Martell</option>
  <option value="Martell">Martell</option>
  <option value="Other">Other</option>
</select><br>
<input type="submit" value="Add"></form>"""
	html+="<p>Who do you think will die next season?</p>"
	html+="""
	<form action="./checking" method="post">
	<input type="checkbox" name="jon_snow" value="dead"> Jon Snow<br>
	<input type="checkbox" name="daenrys_targaryen" value="dead"> Daenarys Targaryen<br>
	<input type="checkbox" name="tyrion_lannister" value="dead"> Tyrion Lannister<br>
	<input type="checkbox" name="arya_stark" value="dead"> Arya Stark<br>
	<input type="checkbox" name="sansa_stark" value="dead"> Sansa Stark<br>
	<input type="checkbox" name="cercei_lannister" value="dead"> Cercei Lannister<br>
	<input type="checkbox" name="jaime_lannister" value="dead"> Jaime Lannister<br>
	<input type="submit" value="Vote It!">
	</form>
	"""
	kill_list('jon_snow', request.POST.get('jon_snow'))
	kill_list('daenrys_targaryen', request.POST.get('daenrys_targaryen'))
	kill_list('tyrion_lannister', request.POST.get('tyrion_lannister'))
	kill_list('arya_stark', request.POST.get('arya_stark'))
	kill_list('sansa_stark', request.POST.get('sansa_stark'))
	kill_list('cercei_lannister', request.POST.get('cercei_lannister'))
	kill_list('jaime_lannister', request.POST.get('jaime_lannister'))
	html+="<table>"
	html+="<tr><th>Character</th><th>Total Score</th></tr>"
	html+="<tr><td>Jon Snow</th><th>"+str(dead_score[0]['Score'])+"</td></tr>"
	html+="<tr><td>Daenarys Targaryen</th><th>"+str(dead_score[1]['Score'])+"</td></tr>"
	html+="<tr><td>Tyrion Lannister</th><th>"+str(dead_score[2]['Score'])+"</td></tr>"
	html+="<tr><td>Arya Stark</th><th>"+str(dead_score[3]['Score'])+"</td></tr>"
	html+="<tr><td>Sansa Stark</th><th>"+str(dead_score[4]['Score'])+"</td></tr>"
	html+="<tr><td>Cercei Lannister</th><th>"+str(dead_score[5]['Score'])+"</td></tr>"
	html+="<tr><td>Jaime Lannister</th><th>"+str(dead_score[6]['Score'])+"</td></tr></table>"
	return htmlify('Welcome', html)

def a3_login():
	global a3_list
	global a3_login
	i=0
	user_name=request.POST.get('Username')
	pass_word=request.POST.get('Password')
	for row in range(0, len(login_list)):
		if [str(user_name), str(pass_word)]==login_list[row]:
			html="<table>\n"
			html+="<tr>\n<th>Name</th>\n<th>House</th>\n<th>Rating</th>\n<th>Votes</th>\n<th>Badassness Level</th>\n</tr>\n"
			for row in a3_list:
				html+="<tr>\n"
				html+="<td>"
				html+=row['Name']
				html+="</td>"
				html+="<td>"
				html+=row['House']
				html+="</td>"
				html+="<td>"
				html+=str(row['Rating'])
				html+="</td>"
				html+="<td>"
				html+=str(row['Votes'])
				html+="</td>\n"
				html+="<td>"
				html+="""<form action="./vote" method="post">"""
				html+="""<input type="radio" name="rate" value="1_"""+str(i)+""""> 1 """
				html+="""<input type="radio" name="rate" value="2_"""+str(i)+""""> 2 """
				html+="""<input type="radio" name="rate" value="3_"""+str(i)+""""> 3 """
				html+="""<input type="radio" name="rate" value="4_"""+str(i)+""""> 4 """
				html+="""<input type="radio" name="rate" value="5_"""+str(i)+""""> 5 """

				html+="</td>"
				html+="</tr>\n"
				i+=1
			html+="</table>"
			html+="""<input type="submit" value="Vote"></form>"""

			html+="""<form action="./add" method="get">
	Name&nbsp; : <input type="text" name="Name"><br>
	House : <select name="House">
	<option value="Stark">Stark</option>
	<option value="Targaryen">Targaryen</option>
	<option value="Lennister">Lennister</option>
	<option value="Greyjoy">Greyjoy</option>
	<option value="Baratheon">Baratheon</option>
	<option value="Tyrell">Tyrell</option>
	<option value="Bolton">Bolton</option>
	<option value="Martell">Martell</option>
	<option value="Martell">Martell</option>
	<option value="Other">Other</option>
	</select><br>
	<input type="submit" value="Add"></form>"""
			html+="<p>Who do you think will die next season?</p>"
			html+="""
			<form action="./checking" method="post">
			<input type="checkbox" name="jon_snow" value="dead"> Jon Snow<br>
			<input type="checkbox" name="daenrys_targaryen" value="dead"> Daenarys Targaryen<br>
			<input type="checkbox" name="tyrion_lannister" value="dead"> Tyrion Lannister<br>
			<input type="checkbox" name="arya_stark" value="dead"> Arya Stark<br>
			<input type="checkbox" name="sansa_stark" value="dead"> Sansa Stark<br>
			<input type="checkbox" name="cercei_lannister" value="dead"> Cercei Lannister<br>
			<input type="checkbox" name="jaime_lannister" value="dead"> Jaime Lannister<br>
			<input type="submit" value="Vote It!">
			</form>
			"""

			kill_list('jon_snow', request.POST.get('jon_snow'))
			kill_list('daenrys_targaryen', request.POST.get('daenrys_targaryen'))
			kill_list('tyrion_lannister', request.POST.get('tyrion_lannister'))
			kill_list('arya_stark', request.POST.get('arya_stark'))
			kill_list('sansa_stark', request.POST.get('sansa_stark'))
			kill_list('cercei_lannister', request.POST.get('cercei_lannister'))
			kill_list('jaime_lannister', request.POST.get('jaime_lannister'))
			html+="<table>"
			html+="<tr><th>Character</th><th>Total Score</th></tr>"
			html+="<tr><td>Jon Snow</th><th>"+str(dead_score[0]['Score'])+"</td></tr>"
			html+="<tr><td>Daenarys Targaryen</th><th>"+str(dead_score[1]['Score'])+"</td></tr>"
			html+="<tr><td>Tyrion Lannister</th><th>"+str(dead_score[2]['Score'])+"</td></tr>"
			html+="<tr><td>Arya Stark</th><th>"+str(dead_score[3]['Score'])+"</td></tr>"
			html+="<tr><td>Sansa Stark</th><th>"+str(dead_score[4]['Score'])+"</td></tr>"
			html+="<tr><td>Cercei Lannister</th><th>"+str(dead_score[5]['Score'])+"</td></tr>"
			html+="<tr><td>Jaime Lannister</th><th>"+str(dead_score[6]['Score'])+"</td></tr></table>"
			return htmlify('Welcome', html)
	html="<h5>WRONG PASSWORD!</h5><a href='./'>Click For Main Page</a>"
	return htmlify('OOPS!', html)
def a3_index():
	return htmlify('Login Page',"""<form action="./login" method="post">
	Username: <input type="text" name="Username">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	Password:<input type="password" name="Password"><br>
	<input type="submit" value="Login">

	</form>""")

def website_index():
    return htmlify('My lovely homepage',
                   """
                   <p><a href="/assignment1/">Click for my assignment 1.</a></p>
                   <p><a href="/assignment2/a2_output.html">Click for my assignment 2.</a></p>
                   <p><a href="/assignment3/">Click for my assignment 3.</a></p>
                   """)

route('/assignment3/','GET', a3_index)
route('/', 'GET', website_index)
route('/assignment3/login', 'POST', a3_login)
route('/assignment3/add', 'GET', a3_add)
route('/assignment3/vote', 'POST', a3_vote)
route('/assignment3/checking', 'POST', checkbox_list)


# This line makes bottle give nicer error messages
debug(True)
# This line is necessary for running on PythonAnywhere
application = default_app()
# The below code is necessary for running this bottle app standalone on your computer.
if __name__ == "__main__":
  run()

