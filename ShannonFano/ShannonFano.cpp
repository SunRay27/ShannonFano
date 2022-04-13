﻿

#include <iostream>
#include "ShannonFanoObject.h"


void TestShannon()
{
    String alphabet = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus elit arcu, luctus eget tempus at, posuere et lorem. In hac habitasse platea dictumst. Sed est arcu, tincidunt ac ullamcorper ac, pretium non metus. Nunc at quam nec lectus malesuada ornare non nec enim. Praesent tristique turpis massa, a vestibulum quam laoreet sed. Nullam convallis pharetra lectus, ac rutrum ex lobortis vel. Sed porta quam eget eros rhoncus commodo. Nam eget fermentum turpis. Nunc convallis est ac velit egestas condimentum. Nunc porta orci a elit elementum venenatis. Etiam sed lacus diam. Curabitur venenatis, dolor vel posuere bibendum, velit ante porta ligula, tempor viverra ligula enim vel lacus. Donec volutpat lectus non turpis aliquet porttitor. Praesent id mauris at mauris pulvinar maximus quis non erat.Curabitur vel viverra quam.Quisque eu lacus mattis, tincidunt massa quis, vulputate neque.Sed at posuere tellus.Suspendisse ac nisl ex.Nam suscipit, metus a posuere sagittis, dolor mi auctor ante, euismod aliquet dolor mauris a metus.Nulla rutrum risus eu augue commodo feugiat.Etiam vitae ligula enim.Etiam non purus nibh.Nulla maximus ex quis mauris convallis porta non in quam.Morbi suscipit facilisis nisl, quis elementum nisi laoreet id.Donec sodales erat vitae magna blandit, in rhoncus risus condimentum.Etiam magna velit, aliquam in euismod id, elementum vel nunc.Mauris orci leo, iaculis ac tempus ut, eleifend in lorem.Curabitur sodales metus id pharetra egestas.Donec laoreet, magna sit amet bibendum ultricies, erat orci euismod metus, vel finibus justo quam at ipsum.Suspendisse justo elit, malesuada nec pharetra id, maximus at metus.Sed vel volutpat libero.Suspendisse ut ex eu velit lacinia fermentum eget vel felis.Suspendisse consequat odio est, et dapibus lacus vestibulum eget.Proin mollis quis augue eget lacinia.Pellentesque tristique feugiat enim eu molestie.Pellentesque nec urna non dolor euismod tincidunt.Sed malesuada mauris sit amet urna porttitor, et condimentum ex porttitor.Praesent id finibus dolor.Sed at ligula at sapien faucibus sollicitudin sit amet vitae tellus.Etiam ante ligula, auctor sit amet semper mattis, placerat quis sapien.Aenean sed ultricies diam, sit amet luctus metus.Curabitur ultricies dignissim nulla, nec finibus augue consectetur tristique.Nulla facilisi.Curabitur lacinia diam a metus tristique, vel placerat eros pretium.Etiam sed eros purus.Ut bibendum nisl urna, ut dignissim est tempor sed.In vestibulum nunc justo, quis efficitur purus vehicula vitae.Donec turpis ipsum, dictum at aliquam sed, hendrerit eu lacus.Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.Nullam sollicitudin, metus eu fermentum sodales, velit risus accumsan justo, id tincidunt orci mi id nisi.Fusce hendrerit, purus ut volutpat consequat, est leo ullamcorper elit, non ultricies urna tortor vitae arcu.Vivamus mollis mattis egestas.Nullam efficitur hendrerit nisl, et ultricies quam semper eu.Nulla hendrerit orci a malesuada porttitor.Praesent varius purus in dui ornare suscipit.Aliquam quis bibendum sem.Proin pharetra nulla ut nulla faucibus porta.Fusce at luctus risus.Morbi accumsan, nunc ut maximus feugiat, quam ex vehicula libero, eu eleifend felis velit in felis.Sed accumsan bibendum hendrerit.Integer eu tellus sed ipsum dictum vestibulum.In est neque, sodales id iaculis et, maximus ac ante.Sed porta massa eu lobortis iaculis.Nullam ullamcorper malesuada diam eget dapibus.Vivamus enim sapien, vulputate semper augue sit amet, ullamcorper laoreet tortor.Ut eget commodo ex.Cras aliquam quam ac suscipit tincidunt.Vestibulum commodo tincidunt libero, eget dapibus velit aliquam eget.Vivamus ut nisl arcu.Ut ut varius mauris.Aliquam congue leo ultrices faucibus porttitor.Duis consectetur nisl massa, ut elementum velit tristique quis. Proin mollis maximus mattis.Nullam facilisis iaculis est et semper.Donec magna justo, aliquam ac lorem eget, fermentum tristique lacus.Aliquam non ligula eros.Lorem ipsum dolor sit amet, consectetur adipiscing elit.In a erat orci.Duis quis fermentum enim, nec suscipit metus.Maecenas tincidunt porta est, quis sagittis magna posuere non.Praesent varius maximus erat, vel accumsan nibh lacinia non.Quisque hendrerit elementum augue, at condimentum tortor commodo ac.Nam et velit eros.Nullam tempor mi eget metus congue, vel semper lorem semper. Aliquam accumsan quam eget ipsum congue aliquet.Morbi vitae vehicula metus.Aenean eu lacus sit amet nisl pellentesque blandit.Phasellus pharetra venenatis eleifend.Phasellus nec cursus nisl, finibus gravida ex.Nullam nunc justo, dapibus non enim nec, faucibus egestas urna.Pellentesque gravida porta facilisis.Proin dapibus ultricies luctus.Duis dignissim eget massa non pharetra.Nunc odio tortor, hendrerit at velit vitae, semper facilisis magna.Duis at tempus sem.Curabitur sit amet neque id elit facilisis pretium. Fusce non sem tincidunt, feugiat arcu vitae, pulvinar turpis.Suspendisse quis leo nulla.Praesent eget justo at ipsum egestas scelerisque.Phasellus eleifend odio eleifend ante hendrerit tincidunt.In auctor neque vitae metus dignissim tempus.Aenean a dui accumsan, interdum risus nec, venenatis lectus.Aliquam pretium sodales erat.Nam quis velit vel ligula suscipit convallis cursus ut ipsum.Nulla pretium hendrerit dui, nec luctus dolor venenatis ac.Nam tempus ligula ac augue convallis viverra.Donec vitae felis rhoncus, tempus est id, molestie mauris.Nullam quis neque eu dolor tincidunt tincidunt ut vitae est. Morbi dictum ipsum vel sapien pharetra, vel placerat augue fermentum.Ut vestibulum ante nec velit ultrices dapibus.Praesent non felis fermentum tellus interdum tempor.Mauris vel interdum leo.Aenean lobortis tortor eu ipsum posuere, cursus luctus libero laoreet.Nullam tincidunt tincidunt velit, eget consectetur risus ornare a.Nam ullamcorper eleifend dolor, id molestie tellus ultricies non.Ut non enim augue.Maecenas placerat pellentesque nunc ut malesuada.Duis hendrerit luctus quam, id interdum ex blandit eget.Curabitur sit amet eleifend erat, quis mollis massa.Morbi eget congue nisi, sed malesuada lacus.Nulla hendrerit, ante ultrices hendrerit efficitur, nulla sapien sollicitudin leo, et dapibus purus nulla non risus.In id euismod sapien, at tristique nisi.Morbi vel massa at lacus auctor lacinia.Nullam ac ante eu felis facilisis malesuada.  Vivamus vitae turpis sit amet neque interdum rutrum quis eget turpis.Nullam hendrerit laoreet dignissim.Aliquam erat volutpat.Maecenas consectetur elit dapibus nunc aliquet feugiat.Maecenas non ex odio.Integer justo massa, accumsan condimentum porta vel, mattis quis arcu.Sed vel sodales arcu.Maecenas dui massa, elementum sed dictum sed, pellentesque eget lorem.Maecenas condimentum sem eget lorem blandit, et eleifend tellus commodo.Suspendisse eget condimentum erat. Etiam aliquet cursus dolor.Pellentesque tortor nisl, pellentesque id massa sed, molestie placerat metus.Nam nec lacus in velit venenatis elementum.Nullam in odio vehicula, mattis quam quis, dignissim turpis.Nulla rhoncus erat at eros ultricies gravida.Aliquam viverra libero metus, ut ornare urna consequat vitae.Praesent vitae rutrum ipsum.Nam eu lobortis urna.In venenatis tellus eu leo luctus dapibus. Lorem ipsum dolor sit amet, consectetur adipiscing elit.Donec ex dui, ullamcorper a elit ut, faucibus gravida dui.Nunc velit magna, porttitor et pharetra at, pretium eget lectus.Sed nec ipsum mauris.Proin ex eros, laoreet sed elementum sit amet, pharetra efficitur risus.Curabitur ligula leo, condimentum ut orci in, sodales dapibus magna.Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.Aenean placerat urna quis posuere pellentesque.Proin porta sapien vitae mauris pellentesque, vel rhoncus magna bibendum.Pellentesque interdum vel felis at mollis.Nulla accumsan suscipit est, ac lobortis sem ornare sit amet. Donec tristique at mauris id ullamcorper.Praesent maximus eros vitae neque fringilla fermentum.Duis ut suscipit massa, malesuada laoreet elit.Etiam et dui pretium, eleifend mauris sed, mollis diam.Nunc porta arcu purus, a scelerisque nulla tristique a.Vestibulum dapibus sem ac facilisis faucibus.In ut est rutrum, pellentesque justo non, faucibus metus. Duis egestas faucibus ante id commodo.Nam vulputate eu velit ac malesuada.Nulla velit eros, tincidunt eget nunc sed, rhoncus volutpat magna.Nullam sed ante vitae risus iaculis laoreet sed in ex.Fusce gravida ligula non velit sagittis hendrerit.Phasellus ut lacus ac quam ullamcorper convallis.Sed a egestas ante.In mollis pulvinar ligula, in laoreet nisi.Donec a urna a diam venenatis viverra vel eu lacus.Vestibulum magna enim, elementum at commodo nec, vehicula at mi.";
    String alphabet2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz,./()!? :;'\"1234567890-=+_<>}{[]\\|~`@#$%^&*";

    ShannonFanoEncoder encoder(alphabet);
    auto operationMap2 = ShannonFanoEncoder::CreateOperationMap(alphabet2);


    String toEncode = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus elit arcu, luctus eget tempus at, posuere et lorem.";
    cout << "String to encode: " << toEncode << endl;
    String encodedString = encoder.Encode(toEncode);
    cout << "Encoded string: " << encodedString << endl;
    String decodedString = encoder.Decode(encodedString);
    cout << "Decoded string: " << decodedString << endl;


    delete operationMap2;
}

int main()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out, 0x0 | 0x70);
    system("CLS");
    SetConsoleOutputCP(1251);

    
    TestShannon();
    
    int a = 1;
    /*
    String bitTest = "abc";
    auto iterator = bitTest.CreateBitIterator();
    
    cout << "String: " << bitTest << " in binary: " << endl;

    List<bool> bits;
    int c = 0;
    while (iterator->HasNext())
    {
        c++;
        int bitNumber = iterator->Next();
        cout << bitNumber;
        bits.Add(bitNumber);
        if (c % 8 == 0)
            cout << " ";
    }

    bitTest.WriteBits(bits);
    cout << "That binary to string: " << bitTest << endl;


    delete iterator;
    */
    }