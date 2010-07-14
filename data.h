#ifndef DATA_H
#define DATA_H

/* Structure de plageThread : chaque ligne : un choix (128k,256k,512k,1M,2M,4M,8M,16M,32M)
 * Dans chaque ligne : 
 * a0,a1 (min,max pour 1 thread T ), 
 * a2,a3,a4 (min T1, max T1/min T2, max T2),
 * a6,a7,a8,a9 (min T1, max T1/min T2, max T2/min T3, max T3) etc.. 
 */
const long plageThread[10][44] = {{0,1698078,0,1036788,1697078,0,776462,1272362,1698078,0,632124,1036788,1383918,1698078,0,538790,884174,1180332,1448880,1698078,0,473010,776472,1036788,1272362,1491548,1698078,0,42355,695478,928722,1140290,1336650,1521558,1698078,0,384890,632124,844422,1036794,1215240,1383924,1544288,1698078},
{0,3588942,0,2195072,3588942,0,1645962,2692310,3588942,0,1341188,2195072,2926662,3588942,0,1144280,1873484,2498682,3064094,3588942,0,1004978,1645968,2195112,2692338,3153764,3588948,0,900104,1474974,1967522,2413674,2827062,3216888,3588942,0,818384,1341204,1789860,2195112,2572094,2926674,3264200,3588949},
{0,7559162,0,4632854,7559162,0,3476844,5677884,7559172,0,2835410,4632870,6170030,7559172,0,2420868,3956028,5269770,6458268,7559172,0,2126810,3476844,4632870,5677892,6646778,7559172,0,1906394,3117294,4154408,509044,5961018,6780252,7559172,0,1733990,2835420,3779654,4632872,5423982,6170058,6879458,7559172},
{0,15485864,0,9505208,15485864,0,7140620,11640584,15485864,0,5828750,9505208,12646680,15485864,0,4977518,8121630,10808328,13235228,15485864,0,4376174,7140620,9505214,11640584,13621162,15485864,0,3923610,6405102,8526258,10443690,1222134,13893318,15485864,0,3570020,5828750,7759814,9505220,11123180,12646694,14096802,15485864},
{0,32452838,0,19949274,32452838,0,15001500,24416240,32452838,0,12251684,19949274,26521800,32452838,0,10470414,17053134,22676264,27750078,32452838,0,9207684,15001514,19949334,24416258,28556600,32452868,0,8259138,13459640,17900658,21911472,25629608,29127588,32452836,0,7516784,12251684,16297092,19949324,23334842,26521812,29552280,32452838},
{0,67867952,0,41774688,67867952,0,31438302,51101222,67867952,0,25693224,41774714,55494938,67867952,0,21965040,35728164,47466038,58058322,67867952,0,19324560,31438302,41774714,51101222,59741780,67867952,0,17339978,28216422,37498634,45870398,53630892,60929330,67867952,0,15786378,25693224,34145628,41774714,48843968,55494938,61817514,67867952},
{0,14165934,0,87290850,14165934,0,65743682,106724288,14165934,0,53752982,87290850,115875990,14165934,0,4597512,74682914,99152174,121217934,14165934,0,40461908,65743682,87290844,106724288,124722194,14165964,0,36320618,59019488,78374292,95829162,111991674,127197794,141650940,0,33072624,53752982,71387000,87290850,102020762,115875990,129041162,141650940},
{0,295075130,0,182036738,295075130,0,137189552,222468300,295075130,0,112221884,182036738,241490462,295075142,0,96026714,155803002,206715438,252597900,295075142,0,84538380,137189552,182036738,222468300,259885548,295075130,0,75900500,123195230,163484534,199803518,233424732,265036352,295075154,0,69134762,112221912,148940292,182036748,212681478,241490468,268868820,29075154},
{0,613651302,0,378947412,613651308,0,285756284,462911634,613651308,0,233865914,378947412,502424642,613651308,0,200178528,324437732,430200710,525490038,613651308,0,176278580,285756284,378947412,462911654,540614528,613651344,0,158311848,256662182,340399370,415844652,485661068,551306682,613651344,0,144226242,233865918,310176242,378947424,442590824,502424652,559265118,613651344}};

#endif