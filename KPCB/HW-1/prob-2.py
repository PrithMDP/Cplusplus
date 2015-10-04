#declare constants
# doing python for the first time please forgive bad code :)
array = []

array.append(0.08167)
array.append(0.01492)
array.append(0.02782)
array.append(0.04253)
array.append(0.12702)
array.append(0.02228)
array.append(0.02015)
array.append(0.06094)
array.append(0.06996)
array.append(0.00153)
array.append(0.00772)
array.append(0.04025)
array.append(0.02406)
array.append(0.06749)
array.append(0.07507)
array.append(0.01929)
array.append(0.00095)
array.append(0.05987)
array.append(0.06327)
array.append(0.09056)
array.append(0.02758)
array.append(0.00978)
array.append(0.02360)
array.append(0.00150)
array.append(0.01974)
array.append(0.00074)
a=0
for i in range (0,26):
	a=a+array[i]	

a=a/26	
print a # this is the mean

pop_var=0
for i in range (0,26): #for all chars
	pop_var = pop_var + ((array[i] - a)*(array[i] - a))

pop_var=pop_var/26
print "pop_var_a" , pop_var # this is the population variance 


char_map={}
plaintext = "ethicslawanduniversitypolicieswarningtodefendasystemyouneedtobeabletothinklikeanattackerandthatincludesunderstandingtechniquesthatcanbeusedtocompromisesecurityhoweverusingthosetechniquesintherealworldmayviolatethelawortheuniversitysrulesanditmaybeunethicalundersomecircumstancesevenprobingforweaknessesmayresultinseverepenaltiesuptoandincludingexpulsioncivilfinesandjailtimeourpolicyineecsisthatyoumustrespecttheprivacyandpropertyrightsofothersatalltimesorelseyouwillfailthecourseactinglawfullyandethicallyisyourresponsibilitycarefullyreadthecomputerfraudandabuseactcfaaafederalstatutethatbroadlycriminalizescomputerintrusionthisisoneofseverallawsthatgovernhackingunderstandwhatthelawprohibitsifindoubtwecanreferyoutoanattorneypleasereviewitsspoliciesonresponsibleuseoftechnologyresourcesandcaenspolicydocumentsforguidelinesconcerningproper"
#plaintext="csfharjzuzlcsmgucqqhrxnnjhahcruzpmgmesmccecmbzqxqsclwnsmcdbsmaczzkcsmsfhljjhidymysrzajcqymbsfzrhlbjtbdqtlccqqsymbhlfrdaglhotcrrgysazlactqdbsmbmlnqmlgrcrcbsqgswgmvcucqsrgmesfnqdrdaglhotcrgmrgcqczjvmqjckzwugnjzrdrgckyvmqrgctlhtdprgswrptjdqzlcgskzwactldrggbyksmbdprmlcbgqatkrrzlbcrcucmnqmagmeemqudyjldqrcrkzwqcrskrhlrcucqcocmykrhcrsornymbhlbjtbhlfcwntjrgnlbgugkdhldqzlchzgkrhkdmtpomkgbwhldcbqhqsfzrxmtktqspdqocbrsfdnqguybwzlcnqmocqrxphegrrmemsfdprysykjsglcrmqckqdwnsvgkjeyhjsfdansqqdybrhlfjzueskjxymbdrggbykjxgrwnsqpdqommqhzhjhrxazpddtjkwqczbsfdankosscqdqytbzlcyasrczasaeyzyecccqykqsyssscsfzrapnycjxaqglgmykgycrankosscqgmrqsrgnlsfhqhqnldmeqdtdpzjkyvqsfzrfmucqlgybihlfsmbdprrzlcugysrgckyvnqmggagsqhdhlcmtzsudazlqcecqwnssmzlzrsmqldwojdyrcqcugduhrrqomkgbgdqnlqcrnnlrgajdsrcndscbfmmkmfwqcrmtpbcrymbbydlrnnjhaxbnatkdlsqemqetgcckgmcranlbcqlhlfnqmocq"
for i in range(0,len(plaintext)):
	a = plaintext[i]
	char_map[a]=0
counter=0
for i in range(0,len(plaintext)):
	a = plaintext[i]
	o= char_map[a]
	o=o+1
	char_map[a]=o
	counter = counter+1

#print "total count ", counter
#print char_map
#print "counter ", counter
new_perc = []

for key in char_map:
	#print char_map[key]
	a = char_map[key]
	a=float(a)
	a=a/840
	new_perc.append(a)

mean=0
for i in range(0,26):
	mean+=new_perc[i]
mean=mean/26


new_pop_var =0 
for i in range (0,26): #for all chars
	new_pop_var = new_pop_var + ((new_perc[i] - mean)*(new_perc[i] - mean))

new_pop_var=new_pop_var/26
print "NEW POP VAR:",new_pop_var # this is the population variance  #WORKS :)




