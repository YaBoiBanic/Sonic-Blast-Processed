//Nick, Jack, Andres
//Github-athon team project lab
//6-3-22


//Names for game ill choose one eventually: Sonic Binary Battle, Sonic Code Quest, Sonic Blast Processed, Sonic Code Chaos
//Program description: Sonic gets digitalized into the a new machine by Eggman, the Error Trapper, putting him into its very code! Sonic must fight his way out of the machine and get back to the real world before Eggman gets a chance to gather all the Chaos Emeralds.
//Program functionality: Skill set can be unlocked by spending skill points, can unlock various passive items and items that can boost his attack or increase his HP for a certain amount of turns, Sonic and enemy both have structures. Enemy structure name, attack, health, and skills, will change at the start of a new battle. Two enemy types and final boss. 7 battles in total. First two are random between ground and flying, second two are random between evolved ground and evolved flying (two more moves). Final boss has same skills as Sonic (the ones the player has unlocked). Sonic can use the Chao Station to get a Chao buddy with a random stat boost. You can then name the Chao. You can have multiples Chaos. You can sort and search your Chao list.

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>

using namespace std;

struct Sonic {
  int attack;
  int maxHP;
  int currentHP;
};

struct Chao {
  string name;
  vector<bool> chaobuffs = {
    false, //Increases Sonic's attack by 15.
    false, //Increases Sonic's maxHP by 50.
    false, //Heals Sonic for 5HP every turn.
    false, //Decreases enemy attack by 25.
    false, //Increase XP gain per battle.
    false //Deal 5 damage to enemies each turn.
  };
  int index;
};

struct enemy {
  string name;
  int attack;
  int maxHP;
  int currentHP;
  vector<bool> enemskills = {
    false, //0 Bash (ground) does damage equal to enemy attack
    false, //1 Ground Slam (ground) does 1 damage and stuns
    false, //2 Debug (Shield Harden Whatever its called) (ground) (heals for 25 HP)
    false, //3 Sting (flying) does damage equal to enemy attack
    false, //4 Stinger Blast (flying) does 20 damage
    false, //5 Hive Bomb (flying) sets bomb that does 50 damage, detonates after random amount of sonic turns between 1 and 3 (game warns you when the bomb is gonna detonate)
    false, //6 Piledriver (ground) does 75 damage
    false, //7 Barrage (ground) 5 strikes, does 10 - 20 damage each (randomly)
    false, //8 Hell Zone Grenade (flying) 10 strikes, does 5 - 8 damage each (randomly)
    false, //9 Finishing Jab (flying) does 125 damage, kills enemy (if attack defeats sonic, sonic loses)
    //final boss set (Metal Sonic)
    false, //10 kick
    false, //11 homing attack
    false, //12 spin dash
    false, //13 light speed attack
    false, //14 sonic wind
    false //15 cyloop
  };
  
};

int start_battle(Sonic &a, enemy b, vector<bool> skillset, Chao c);
void downtime(Sonic &snoc, vector<Chao> &chaoset, vector<bool> &skillset);
void chaostation(vector<Chao> &chaoset);
void chaocheck(vector<Chao> &chaoset);
int binarySearch(vector<Chao> arr, int l, int r, int x);
void BubbleSort(vector<Chao> &chaoset);
void buyskills(vector<bool> &skillset, Sonic &a);
void calcexp(int tc, int base, vector<Chao> &chaoset);
int turn_count = 0;
int eggmanProgress = 0;
int exps = 0;

int main() {
  do {
    srand(time(0));
    vector<bool> skillset = {false, false, false, false, false}; //1. Homing Attack, 2. Spin Dash, 3. Light Speed Attack, 4. Sonic Wind, 5. Cyloop
    vector<Chao> chaoset;
    string emptyString;

    printf("\033c");
    cout << "Sonic: Blast Processed\n\n";
    cout << "Press any button to start\n";
    
    getline(cin, emptyString);
    printf("\033c");
  
    Sonic sonic;
    sonic.maxHP = 150;
    sonic.currentHP = 150;
    sonic.attack = 25;
  
    cout << "Sonic was doing his usual daily routine: Wake up, take a few trips around the zones, check on his friends, and foil Dr. Eggman's plans. While running through Scrap Brain Zone, Sonic was able to catch Eggman in the middle of setting up one of his newest machines." << endl << endl << "Sonic: Woah, looks like you got yourself a shiny new toy, huh Eggman? What's this one gonna try against me? Suck me up like a vacuum? Send me to the future for the 5th time? Maybe it's just a calculator for all I know!" << endl << endl << "Dr. Eggman: Sonic, I've been expecting you." << endl << endl << "Sonic: You always say that. Doesn't change the fact I always beat you sunny side up!" << endl << endl << "Dr. Eggman: Well you were right about one thing earlier. This machine is a calculator. A very unique calculator. A computer that will trap you inside itself!" << endl << endl << "Sonic: Wow Eggman, very original. I'll just Spin Dash right out of it. What's gonna make this different from the other 30 times?" << endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    cout << "Dr. Eggman: Oh, foolish rodent. You won't be trapped inside the machine physically. But I don't need to explain everything to you. Error Trapper, get this bug out of my sight!" << endl << endl << "Sonic: I don't even look like an insect!" << endl << endl << "The Error Trapper began to extend what looked like claws out of its sides. However, these claws looked almost pixelated, similar to the reality bending abilites of the Phantom Ruby. Sonic dashed out of the way before it could grasp him. The machine began to make weird sounds." << endl << endl << "Sonic: Sounds just like the time I broke the Miles Electric while on a run. Tails really should've put a screen protector on that thing." << endl << endl << "While Sonic was distracted making snary remarks at the machine, the Error Trapper created a digital speed bump, tripping Sonic. It grabbed Sonic by the feet and brought him closer to its large display on the front of its body. The screen lit up with green text that says \"Beginning Capture...\"" << endl << endl << "Dr. Eggman: Funs over, Sonic. As for me, the fun has just begun. Hasta la vista!" << endl << endl << "Sonic: Really took you 10 years to say that correctly?" << endl << endl << "The doctor fleed in his Eggmobile as the Error Trapper begin emitting a green light from the display. Sirens began to go off on the machine. Sonic's physical form began to pixelate, and he was dragged into the machine's display. \"Capture Complete.\"" << endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    cout << "Sonic: Ow, my head! What is this place?" << endl << endl << "Sonic took in his surroundings. Everything seemed so familiar, but something was off. Not that this was the first time something like that had happened to him. However, the plains were lifeless. The flowers were still, the grass did not dance with the wind, and there was not a cloud in the sky. But more importantly..." << endl << endl << "Sonic: Why am I made of numbers!? Green isn't really my color, either! None of this makes sense to me. Where did Eggman go? What did that robot do? I gotta find an answer, and fast!" << endl << endl << "Before Sonic could start his journey, something began materializing in the air. A Badnik appeared, but only its shape seemed intact." << endl << endl << "Sonic: I don't know what you are, but if it's gonna take a beatdown to get some intel out of you, I'm more than ready!"<< endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    enemy first;
    first.name = "Motobug";
    first.attack = 10;
    first.maxHP = 100;
    first.currentHP = 100;
    first.enemskills[0] = true;
    first.enemskills[1] = true;
    if(chaoset.size() > 0) {
      calcexp(start_battle(sonic, first, skillset, chaoset[0]), 100, chaoset);
    } else {
      Chao cybershell;
      calcexp(start_battle(sonic, first, skillset, cybershell), 100, chaoset);
    }
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    cout << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    cout << "Sonic: I guess they weren't much of a talker. Either way, I'm starting to get an idea of what's happening. Looks like baldy figured out how to trap me inside that scrapheap's code. I have to figure out a way out of this, and fast. The longer I stay in here, the more time Eggman gets to take the Chaos Emeralds. I don't got a clue when the next enemy will take me by surprise, so I might as well use this time wisely." << endl << endl << "(For every turn you take in battle, Dr. Eggman gets closer to capturing a Chaos Emerald. Once he collects all seven, Sonic's journey will end. Finish off all the enemies as fast as possible to make sure you can stop him in time.)" << endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    downtime(sonic, chaoset, skillset);
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    printf("\033c");
    cout << "Sonic: There's gotta be a way out of here, I know there is! I don't care how many bots I have to clobber, I won't let Eggman get his way!" << endl << endl << "Sonic sensed something behind him. He stopped and turned. Nothing was there. Suddenly a projectile was hurdling towards him from above. Sonic rolled out of the way. He looked upwards to see another enemy, this time a Buzz Bomber made of code, just like the Motobug from earlier." << endl << endl << "Sonic (Thinking): There's gotta be something that creating these enemies. If I can find that, I can destroy it and set myself free from the inside." << endl << endl << "Sonic: Alright, time for round 2. Let's rock!" << endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    enemy second;
    second.name = "BuzzBomber";
    second.attack = 15;
    second.maxHP = 150;
    second.currentHP = 150;
    second.enemskills[3] = true;
    second.enemskills[4] = true;
    second.enemskills[5] = true;
    if(chaoset.size() > 0) {
      calcexp(start_battle(sonic, second, skillset, chaoset[0]), 150, chaoset);
    } else {
      Chao cybershell;
      calcexp(start_battle(sonic, second, skillset, cybershell), 150, chaoset);
    }
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    cout << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    cout << "Sonic looked to the floating point clouds." << endl << endl << "Sonic: There seems to be an energy coming from the west. Guess I'll be heading there." << endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    downtime(sonic, chaoset, skillset);
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    printf("\033c");
    cout << "Sonic glided across the terrain, taking in his surroundings." << endl << endl << "Sonic: Looks like Eggman has a knack for level design. Granted, I think I realized that back when I first visited Star Light Zone." << endl << endl << "Sonic sprinted towards what seemed to be a power plant, with the roof of the complex open and releasing a green energy. As Sonic stopped at its entrance, another enemy began to materialize in front of Sonic." << endl << endl << "Sonic: What are you, some gatekeeper? Well you won't be stopping me. Let's dance, nuts and bolts!" << endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    int randnum1 = random()%1;
    enemy third;
    if (randnum1 == 0) {
      third.name = "Caterkiller";
      third.attack = 20;
      third.maxHP = 200;
      third.currentHP = 200;
      third.enemskills[0] = true;
      third.enemskills[1] = true;
      third.enemskills[2] = true;
    } else {
      third.name = "Buzzer";
      third.attack = 20;
      third.maxHP = 200;
      third.currentHP = 200;
      third.enemskills[3] = true;
      third.enemskills[4] = true;
      third.enemskills[5] = true;
    }
    if(chaoset.size() > 0) {
      calcexp(start_battle(sonic, third, skillset, chaoset[0]), 200, chaoset);
    } else {
      Chao cybershell;
      calcexp(start_battle(sonic, third, skillset, cybershell), 200, chaoset);
    }
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    cout << "Sonic adjusted to the digital landscape. His attack and HP were increased.\n";
    sonic.attack+=5;
    sonic.currentHP+=25;
    sonic.maxHP+=25;
    cout << endl << "Press any button to continue" << endl;
    getline(cin, emptyString);
    printf("\033c");
    cout << "Sonic: Come on, dude! You're supposed to keep me out, not let me in! No wonder you get paid minimum wage. Alright, let's see what this little liar's REAL security is like." << endl << endl << "Press any button to continue" << endl;
    getline(cin, emptyString);
    printf("\033c");
    downtime(sonic, chaoset, skillset);
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    printf("\033c");
      cout << "Sonic boosted through all the obstacles in his path, getting closer to what seemed to be the reactor's core. Suddenly 3 doors closed in the distance. Another enemy began to materialize." << endl << endl << "Sonic: Aw, a gauntlet for little ol' me? Really rolling out the red carpet here, guys." << endl << endl << "Press any button to continue" << endl;
    getline(cin, emptyString);
    printf("\033c");
    int randnum2 = random()%1;
    enemy fourth;
    if (randnum2 == 0) {
      fourth.name = "Egg Pawn";
      fourth.attack = 25;
      fourth.maxHP = 300;
      fourth.currentHP = 300;
      fourth.enemskills[0] = true;
      fourth.enemskills[1] = true;
      fourth.enemskills[2] = true;
      fourth.enemskills[6] = true;
      fourth.enemskills[7] = true;
    } else {
      fourth.name = "Bee Bot";
      fourth.attack = 25;
      fourth.maxHP = 300;
      fourth.currentHP = 300;
      fourth.enemskills[3] = true;
      fourth.enemskills[4] = true;
      fourth.enemskills[5] = true;
      fourth.enemskills[8] = true;
      fourth.enemskills[9] = true;
    }
    if(chaoset.size() > 0) {
      calcexp(start_battle(sonic, fourth, skillset, chaoset[0]), 300, chaoset);
    } else {
      Chao cybershell;
      calcexp(start_battle(sonic, fourth, skillset, cybershell), 300, chaoset);
    }
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    cout << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    downtime(sonic, chaoset, skillset);
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    printf("\033c");
    int randnum3 = random()%1;
    enemy fifth;
    if (randnum2 == 0) {
      fifth.name = "Egg Fighter";
      fifth.attack = 30;
      fifth.maxHP = 400;
      fifth.currentHP = 400;
      fifth.enemskills[0] = true;
      fifth.enemskills[1] = true;
      fifth.enemskills[2] = true;
      fifth.enemskills[6] = true;
      fifth.enemskills[7] = true;
    } else {
      fifth.name = "Killer Bee";
      fifth.attack = 30;
      fifth.maxHP = 400;
      fifth.currentHP = 400;
      fifth.enemskills[3] = true;
      fifth.enemskills[4] = true;
      fifth.enemskills[5] = true;
      fifth.enemskills[8] = true;
      fifth.enemskills[9] = true;
    }
     if(chaoset.size() > 0) {
      calcexp(start_battle(sonic, fifth, skillset, chaoset[0]), 400, chaoset);
    } else {
      Chao cybershell;
      calcexp(start_battle(sonic, fifth, skillset, cybershell), 400, chaoset);
    }
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    cout << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    downtime(sonic, chaoset, skillset);
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    printf("\033c");
    int randnum4 = random()%1;
    enemy sixth;
    if (randnum2 == 0) {
      sixth.name = "Egg Guardian";
      sixth.attack = 35;
      sixth.maxHP = 500;
      sixth.currentHP = 500;
      sixth.enemskills[0] = true;
      sixth.enemskills[1] = true;
      sixth.enemskills[2] = true;
      sixth.enemskills[6] = true;
      sixth.enemskills[7] = true;
    } else {
      sixth.name = "Red Killer Bee";
      sixth.attack = 35;
      sixth.maxHP = 500;
      sixth.currentHP = 500;
      sixth.enemskills[3] = true;
      sixth.enemskills[4] = true;
      sixth.enemskills[5] = true;
      sixth.enemskills[8] = true;
      sixth.enemskills[9] = true;
    }
     if(chaoset.size() > 0) {
      calcexp(start_battle(sonic, sixth, skillset, chaoset[0]), 500, chaoset);
    } else {
      Chao cybershell;
      calcexp(start_battle(sonic, sixth, skillset, cybershell), 500, chaoset);
    }
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    cout << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    downtime(sonic, chaoset, skillset);
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    printf("\033c");
    cout << "Sonic: And so, our hero triumphs over The Three Stooges blocking his path, and makes his way to slay the dragon." << endl << endl << "Sonic paced towards the reactor core's control panel. As Sonic touched the panel, the reactor began to freak out. It started bursting with energy and suddenly concentrated to materialize another enemy. However, this enemy was no ordinary foe. Sonic, recognizing the shape forming before his eyes, frowned and got into a battle stance. The Badnik fell to the ground, and slowly looked up to Sonic. The enemy was none other than..." << endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    cout << "Sonic: Metal Sonic! Of course the machine made its last stand him. Wait, something's not right. All the other Badniks seemed deformed. But you seem perfectly intact..." << endl << endl << "Sonic squinted at his metal counterpart." << endl << endl << "Sonic: Just like me..." << endl << endl << "Sonic (Thinking): Metal must have injected his own programming into the Error Trapper, just so he could chase me down. This bot's hatred for me really has no limit." << endl << endl << "Sonic: I know we usually race to prove who's the real Sonic, but this time I'm tired of your scrap, Metal. I'm ending this, here and now." << endl << endl << "Metal's formerly red eyes shined in the glow of the reactor. Sonic knew he agreed to the duel. Both bolted towards each other." << endl << endl << "(In this battle, Metal Sonic will share the same skills you have unlocked on your journey.)" << endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    enemy metal;
    metal.name = "Metal Sonic";
    metal.attack = sonic.attack;
    metal.maxHP = 750;
    metal.currentHP = 750;
    int j = 0;
    for (int i = 10; i <= 15; i++) {
      if (skillset[j] == true) {
        metal.enemskills[i] = true;
        j++;
      }
    }
    if(chaoset.size() > 0) {
      calcexp(start_battle(sonic, metal, skillset, chaoset[0]), 500, chaoset);
    } else {
      Chao cybershell;
      calcexp(start_battle(sonic, metal, skillset, cybershell), 500, chaoset);
    }
    if(sonic.currentHP <= 0 || eggmanProgress > 6) {
      break;
    }
    cout << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
    cout << "Sonic roundhouse kicked Metal Sonic into the reactor's core. The green energy began to consume Metal. Metal held his arm out, as if he was trying to grasp Sonic." << endl << endl << "Sonic: See you on the outside, look-alike." << endl << endl << "Metal Sonic dissipated into the core, and Sonic felt the ground shake beneath him." << endl << endl << "Sonic: Looks like that did the trick! Time to get out of this wack place! Oh, I need a cool one-liner first before I leave! How abou-" << endl << endl << "Before Sonic could finish, the core bursted with a blinding light, consuming everything in the digital world." << endl << endl << "Press any button to continue";
    getline(cin, emptyString);
    printf("\033c");
  cout << "Sonic: Ow, my head! Again!" << endl << endl << "Sonic took a quick glance at his surroundings. He was back in the same lab area in Scrap Brain Zone he was consumed by the Error Trapper in. Sonic looked behind him, and just as he had thought, he was greeted by a demolished Error Trapper. Alongside it, Metal Sonic laid on the ground, smoking from his jet engine." << endl << endl << "Sonic: Looks like everything worked out in the end. There's just one thing missing, and that's the Chaos Emeralds back where they belong. It doesn't matter how long or far you trap me, you'll never be faster than me!" << endl << endl << "Sonic peeled out from the lab and went to take down Eggman, thus finishing his daily routine. The End." << endl << endl << "THANK YOU FOR PLAYING";
  } while (false);
  if (eggmanProgress > 6) {
    cout << endl << "Eggman has collected all 7 Chaos Emeralds before Sonic could escape the Error Trapper. The Eggman Empire shall reign supreme..." << endl << "GAME OVER\n";
  }
}

int start_battle(Sonic &a, enemy b, vector<bool> skillset, Chao c) {
  cout << "Sonic encounters " + b.name << endl;
  int counter = 1;
  bool turnLoop = true;
  bool errorflag = true;
  int choice;
  bool isStunned = false;
  int hiveBomb_timer = -1;
  int battle_turns = 0;

  if(c.chaobuffs[0]) {
    a.attack = a.attack+15;
  } else if(c.chaobuffs[3]) {
    b.attack = b.attack-10;
  } else if(c.chaobuffs[1]) {
    a.currentHP+=50;
    a.maxHP+=50;
  }

  while(turnLoop && eggmanProgress < 7) {
    if(a.currentHP < 100) {
      cout << "\nSonic:\t\t\t HP: " << a.currentHP << "/" << a.maxHP << "\t\tAttack: " << a.attack << endl;
    } else {
      cout << "\nSonic:\t\t\t HP: " << a.currentHP << "/" << a.maxHP << "\tAttack: " << a.attack << endl;
    }
    if(b.currentHP < 100) {
      cout << b.name + ":\t\t HP: " << b.currentHP << "/" << b.maxHP << "\t\tAttack: " << b.attack << endl;
    } else {
      cout << b.name + ":\t\t HP: " << b.currentHP << "/" << b.maxHP << "\tAttack: " << b.attack << endl;
    }
    if(!isStunned) {
      cout << "What will Sonic do?\n\n";
      cout << "0. Check Eggman's Progress\n";
      cout << "1. Kick\n"; //single strike that does attack damage
      if(skillset[0]) {
        cout << "2. Homing Attack\n"; //single strike that does attack + 10 damage
        counter++;
      }
      if(skillset[1]) {
        cout << "3. Spin Dash\n"; //single strike that does 1.2x, 1.4x, 1.6x attack damage depending on how fast Sonic revs up (random)
        counter++;
      }
      if(skillset[2]) {
        cout << "4. Light Speed Attack\n"; //single strike that takes 25% of enemy's attack + Sonic's attack damage
        counter++;
      }
      if(skillset[3]) {
        cout << "5. Sonic Wind\n"; //triple strike that does attack damage + random value between 5 and 10 for each strike
        counter++;
      }
      if(skillset[4]) {
        cout << "6. Cyloop\n"; //single strike with 4x attack damage
        counter++;
      }
      errorflag = true;
      while(errorflag) {
      
        string ans;
        getline(cin, ans);
        try {
          choice = stoi(ans);
          if(choice >= 0 && choice <= counter) {
            errorflag = false;
          }
          else cout << "Invalid choice, please try again.\n";
        } catch(invalid_argument) {
          cout << "Invalid choice, please try again.\n";
        } catch(out_of_range) {
          cout << "Invalid choice, please try again.\n";
        }
      }
      if(choice == 0) {
        cout << "Eggman has gotten " << eggmanProgress << " of the Chaos Emeralds.";
        continue;
      }
      if(choice == 1) {
        cout << "Sonic kicks " + b.name + " for " << a.attack << " damage.\n";
        b.currentHP = b.currentHP - a.attack;
      }
      if(choice == 2) {
        cout << "Sonic homing attacks " + b.name + " for " << a.attack+10 << " damage.\n";
        b.currentHP = b.currentHP - (a.attack+10);
      }
      if(choice == 3) {
        int randnum = random()%3;
        double multiplier;
        if(randnum == 0) multiplier = 1.2;
        else if(randnum == 1) multiplier = 1.4;
        else multiplier = 1.6;
        cout << "Sonic spin dashes " + b.name + " for " << round(a.attack*multiplier) << " damage.\n";
        b.currentHP = b.currentHP - round(a.attack*multiplier);
      }
      if(choice == 4) {
        cout << "Sonic gathers energy from " + b.name + " and unleashes a Light Speed Attack for " << a.attack+(b.attack/4) << " damage.\n";
        b.currentHP = b.currentHP - (a.attack+(b.attack/4));
      }
      if(choice == 5) {
        for(int i = 0; i < 3; i++) {
          int randnum = random()%6+5;
          cout << "Sonic uses Sonic Wind on " + b.name + " for " << a.attack+randnum << " damage.\n";
          b.currentHP = b.currentHP - (a.attack+randnum);
        }
      }
      if(choice == 6) {
        cout << "Sonic uses Cyloop, creating a ring around " + b.name + " for " << a.attack*4 << " damage.\n";
        b.currentHP = b.currentHP - (a.attack*4);
      }
    }
    isStunned = false;
  
    if(b.currentHP > 0) {
      int enemchoice;
      bool enemflag = true;
      while(enemflag) {
        int randnum = random()%16;
        if(b.enemskills[randnum]) {
          enemflag = false;
          enemchoice = randnum;
          if(randnum == 2 && b.currentHP+25 > b.maxHP) {
            enemflag = true;
          }
          if(randnum == 9 && a.currentHP < 125) {
            enemflag = true;
          }
          if(randnum == 5 && hiveBomb_timer > 0) {
            enemflag = true;
          }
        }
      }
      /*
        ENEMY ATTACKS

        selected at random above
        15 possible attacks (including metal sonic attacks)
      */
      if(enemchoice == 0) {
        cout << "The " + b.name + " bashes Sonic, doing " << b.attack << " damage.\n";
        a.currentHP = a.currentHP-b.attack;
      }
      if(enemchoice == 1) {
        cout << "The " + b.name + " ground slams Sonic, doing 1 damage.\n";
        a.currentHP = a.currentHP-1;
        isStunned = true;
      }
      if(enemchoice == 2) {
        cout << "The " + b.name + " debugs itself, healing 25 damage.\n";
        b.currentHP = b.currentHP+25;
      }
      if(enemchoice == 3) {
        cout << "The " + b.name + " stings Sonic, doing " << b.attack << " damage.\n";
        a.currentHP = a.currentHP-b.attack;
      }
      if(enemchoice == 4) {
        cout << "The " + b.name + " fires a projectile out of its stinger at Sonic, doing 20 damage.\n";
        a.currentHP = a.currentHP-20;
      }
      if(enemchoice == 5) {
        hiveBomb_timer = random()%3+3;
        cout << "The " + b.name + " plants a Hive Bomb on Sonic, setting a bomb that will do 50 damage in " << hiveBomb_timer-1 << " turns.\n";
      }
      if(enemchoice == 6) {
        cout << "The " + b.name + " piledrivers Sonic, doing 40 damage.\n";
        a.currentHP = a.currentHP-40;
      }
      if(enemchoice == 7) {
        for(int i = 0; i < 4; i++) {
          int randnum = random()%7+5;
          cout << "The " + b.name + " barrages Sonic, doing " << randnum << " damage.\n";
          a.currentHP = a.currentHP-randnum;
        }
      }
      if(enemchoice == 8) {
        for(int i = 0; i < 10; i++) {
          int randnum = random()%4+5;
          cout << "The " + b.name + " uses Hell Zone Grenade on Sonic, doing " << randnum << " damage.\n";
          a.currentHP = a.currentHP-randnum;
        }
      }
      if(enemchoice == 9) {
        cout << "The " + b.name + " Finishing Jabs Sonic, doing 125 damage and deleting itself.\n";
        a.currentHP = a.currentHP-125;
        b.currentHP = 0;
      }
      if(enemchoice == 10) {
        cout << "Metal Sonic kicks the Sonic for " << b.attack << " damage.\n";
        a.currentHP = a.currentHP - b.attack;
      }
      if(enemchoice == 11) {
        cout << "Metal Sonic homing attacks Sonic for " << b.attack+10 << " damage.\n";
        a.currentHP = a.currentHP - (b.attack+10);
      }
      if(enemchoice == 12) {
        int randnum = random()%3;
        double multiplier;
        if(randnum == 0) multiplier = 1.2;
        else if(randnum == 1) multiplier = 1.4;
        else multiplier = 1.6;
        cout << "Metal Sonic spin dashes Sonic for " << round(b.attack*multiplier) << " damage.\n";
        a.currentHP = a.currentHP - round(b.attack*multiplier);
      }
      if(enemchoice == 13) {
        cout << "Metal Sonic gathers energy from Sonic and unleashes a Light Speed Attack for " << b.attack+(a.attack/4) << " damage.\n";
        a.currentHP = a.currentHP - (b.attack+(a.attack/4));
      }
      if(enemchoice == 14) {
        for(int i = 0; i < 3; i++) {
          int randnum = random()%6+5;
          cout << "Metal Sonic uses Sonic Wind on Sonic for " << b.attack+randnum << " damage.\n" << endl;
          a.currentHP = a.currentHP - (b.attack+randnum);
        }
      }
      if(enemchoice == 15) {
        cout << "Metal Sonic uses Cyloop, creating a ring around Sonic for " << b.attack*4 << " damage.\n" << endl;
        a.currentHP = a.currentHP - (b.attack*4);
      }
    }
    turn_count++;
    battle_turns++;
    hiveBomb_timer--;
    if(hiveBomb_timer == 0) {
      cout << "The Hive Bomb explodes, dealing 50 damage to Sonic.\n" << endl;
      a.currentHP = a.currentHP-50;
      hiveBomb_timer = -1;
    }

    if(c.chaobuffs[5]) {
      cout << c.name + " punches " + b.name + " for 5 damage.\n" << endl;
      b.currentHP = b.currentHP-5;
    }
    
    if(turn_count%20 == 0) eggmanProgress++;
    
    if(a.currentHP <= 0) {
      cout << endl << "\"I-I can't let my friends down... No...\"" << endl << endl << "Sonic has fallen." << endl << "GAME OVER";
      break;
    }
    if(b.currentHP <= 0 && a.currentHP > 0) {
      cout << "Sonic defeated " + b.name << ". Eggman has collected " << eggmanProgress << " of the Chaos Emeralds in total." << endl;
      turnLoop = false;
    }

    if(c.chaobuffs[2] && !isStunned) {
      cout << c.name + " healed Sonic for 5 HP.\n" << endl;
      a.currentHP = a.currentHP + 5;
      if(a.currentHP > a.maxHP) a.currentHP = a.maxHP;
    }

    if(eggmanProgress > 6) {
      a.currentHP = 0;
    }
  }
  if(c.chaobuffs[0]) {
    a.attack = a.attack-15;
  } else if(c.chaobuffs[1]) {
    a.currentHP = a.currentHP-50;
    a.maxHP = a.maxHP-50;
  }
  return battle_turns;
}

void downtime (Sonic &snoc, vector<Chao> &chaoset, vector<bool> &skillset) {
  bool rest = true;
  int choice;
  while (rest) {
    cout << "HP: " << snoc.currentHP << "/" << snoc.maxHP << "\t\tAttack: " << snoc.attack << "\nExp: " << exps << endl;
    cout << "What would you like to do?\n\n";
    cout << "0. Check Eggman's Progress\n";
    cout << "1. Rest (Restore HP) (Adds 10 turns) (Starts next battle)\n";
    cout << "2. Use Chao Station\n";
    cout << "3. Improve your skills\n";
    cout << "4. Continue\n";
    bool errorflag = true;
    while(errorflag) {
      string ans;
      getline(cin, ans);
      try {
        choice = stoi(ans);
        if(choice >= 0 && choice <= 4) {
          errorflag = false;
        }
        else cout << "Invalid choice, please try again.\n" << endl;
      } catch(invalid_argument) {
        cout << "Invalid choice, please try again.\n" << endl;
      } catch(out_of_range) {
        cout << "Invalid choice, please try again.\n" << endl;
      }
    }
    if (choice == 0) {
      cout << "Eggman has gotten " << eggmanProgress << " of the Seven Chaos Emeralds.\n" << endl;
      continue;
    }
    if (choice == 1) {
      cout << "Sonic lied down on the integer covered ground. To his surprise, it was quite warm. Sonic closed his eyes for a bit.\n" << endl;
      snoc.currentHP = snoc.maxHP;
      for(int i = 0; i < 10; i++) {
        turn_count++;
        if(turn_count%20 == 0) eggmanProgress++;
        if (eggmanProgress > 6) {
          cout << "However, this rest was short-lived, as Sonic checked Eggman's progress to see he had gotten all 7 Chaos Emeralds." << endl << "\"Maybe I shouldn't have gotten too comfortable...\"" << endl << "GAME OVER";
  
          return;
        }
      }
      cout << "Sonic's HP was restored.\n\n";
      rest = false;
      cout << "Press any button to continue";
      string emptyString;
      getline(cin, emptyString);
      printf("\033c");
      continue;
    }
    if (choice == 2) {
      chaostation(chaoset);
      continue;
    }
    if (choice == 3) {
      buyskills(skillset, snoc);
    }
    if (choice == 4) {
      rest = false;
    }
  }
}

void chaostation(vector<Chao> &chaoset) {
  Chao adoptable;
  bool chaoflag = true;
  int randnum;
  while(chaoflag) {
    chaoflag = false;
    randnum = random()%6;
    for(int i = 0; i < chaoset.size(); i++) {
      if(chaoset[i].chaobuffs[randnum]) chaoflag = true;
    }
    if(chaoset.size() >= 6) {
      chaoflag = false;
      cout << "Would you like to check your Chao inventory? (y/n)" << endl;
      string resp;
      getline(cin, resp);
      if(resp == "y" || resp == "Y") {
        chaocheck(chaoset);
        return;
      } else {
        cout << "You exit the Chao Station." << endl;
        return;
      }
    }
  }

  adoptable.chaobuffs[randnum] = true;

  cout << "Would you like to purchase a Chao for 200 exp? (y/n)" << endl;
  string resp;
  getline(cin, resp);
  if(resp == "y" || resp == "Y") {
    if(exps >= 200) {
      cout << "You successfully purchase a Chao. What do you name it?" << endl;
      getline(cin, resp);
      adoptable.name = resp;
      chaoset.push_back(adoptable);
      cout << "You decide to name the Chao " + adoptable.name + ". It will now be able to grant you its power." << endl;
      exps = exps - 200;
    } else {
      cout << "You do not have enough exp to purchase a Chao." << endl;
    }
  } else {
    cout << "You decided not to purchase a Chao." << endl;
  }

  if(chaoset.size() > 0) {
    cout << "Would you like to check your Chao inventory? (y/n)" << endl;
    getline(cin, resp);
    if(resp == "y" || resp == "Y") {
      chaocheck(chaoset);
    } else {
      cout << "You exit the Chao Station." << endl;
    }
  }
}

void chaocheck(vector<Chao> &chaoset) {
  BubbleSort(chaoset);
  cout << "Chao Inventory:\n" << endl;
  for(int i = 0; i < chaoset.size(); i++) {
    cout << i+1 << ". " + chaoset[i].name + ":\t\t\t";
    if(chaoset[i].chaobuffs[0]) cout << "Increases Sonic's attack by 15.\n" << endl;
    else if(chaoset[i].chaobuffs[1]) cout << "Increases Sonic's max HP by 50.\n" << endl;
    else if(chaoset[i].chaobuffs[2]) cout << "Heals Sonic for 5 HP every turn in battle.\n" << endl;
    else if(chaoset[i].chaobuffs[3]) cout << "Decreases the enemy's attack by 10\n" << endl;
    else if(chaoset[i].chaobuffs[4]) cout << "Increases the XP gained after battle.\n" << endl;
    else if(chaoset[i].chaobuffs[5]) cout << "Deals 5 damage to enemies at the end of every turn.\n" << endl;
    chaoset[i].index = i;
  }

  cout << "Which Chao would you like to set as active?" << endl;
  
  bool errorflag = true;
  int choice;
  while(errorflag) {
    string ans;
    getline(cin, ans);
    try {
      choice = stoi(ans);
      if(choice > 0 && choice <= chaoset.size()) {
        errorflag = false;
      }
      else cout << "Invalid choice, please try again." << endl;
    } catch(invalid_argument) {
      cout << "Invalid choice, please try again." << endl;
    } catch(out_of_range) {
      cout << "Invalid choice, please try again." << endl;
    }
  }

  choice = binarySearch(chaoset, 0, chaoset.size()-1, choice-1);

  Chao temp = chaoset[choice];
  chaoset[choice] = chaoset[0];
  chaoset[0] = temp;
}

int binarySearch(vector<Chao> arr , int l, int r, int x)
  {
    if (r >= l) 
      {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid].index == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid].index > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
      }
 
    // We reach here when element is not
    // present in array
    return -1;
  }

void BubbleSort(vector<Chao> &chaoset) {
  int i, j, flag = 1; // set flag to 1 to start first pass
  Chao temp; // holding variable
  for(i = 1; i <= chaoset.size() && flag; i++) {
    flag = 0;
    for (j=0; j < chaoset.size()-1; j++) {
      if (chaoset[j+1].name < chaoset[j].name) { 
        temp = chaoset[j];// swap elements
        chaoset[j] = chaoset[j+1];
        chaoset[j+1] = temp;
        flag = 1; // indicates that a swap occurred.
      }
    }
  }
}

void buyskills(vector<bool> &skillset, Sonic &a) {
  cout << "Attack: " << a.attack << endl;
  cout << "HP: " << a.currentHP << "/" << a.maxHP << endl;
  cout << "Current skills:\n" << endl;
  cout << "1. Kick: a single strike that does damage equal to Sonic's attack.\n" << endl;
  if(skillset[0]) cout << "2. Homing Attack: a single strike that does damage equal to Sonic's attack + 10.\n" << endl;
  if(skillset[1]) cout << "3. Spin Attack: a single strike that does more damage the faster Sonic spins (random).\n";
  if(skillset[2]) cout << "4. Light Speed Attack: a single strike that does damage equal to Sonic's attack plus 25% of the enemy's attack.\n" << endl;
  if(skillset[3]) cout << "5. Sonic Wind: Sonic generates a powerful wind that strikes the foe 3 times, dealing a random amount of damage slightly greater than Sonic's attack stat each time.\n" << endl;
  if(skillset[4]) cout << "6. Cyloop: Sonic creates a ring around the foe, dealing massive damage.\n" << endl;

  cout << "Available Skills:\n" << endl;
  cout << "1. Increase Attack by 5.\t\t75 exp.\n" << endl;
  cout << "2. Increase maximum HP by 10\t100 exp.\n" << endl;
  if(!skillset[0]) {
    cout << "3. Homing Attack: 100 exp.\n" << endl;
  } else if(!skillset[1]) {
    cout << "3. Spin Attack: 150 exp.\n" << endl;
  } else if(!skillset[2]) {
    cout << "3. Light Speed Attack: 200 exp.\n" << endl;
  } else if(!skillset[3]) {
    cout << "3. Sonic Wind: 250 exp.\n" << endl;
  } else if(!skillset[4]) {
    cout << "3. Cyloop: 300 exp.\n" << endl;
  }
  cout << "4. Leave Shop.\n";

  bool errorflag = true;
  int choice;
  while(errorflag) {
    string ans;
    getline(cin, ans);
    try {
      choice = stoi(ans);
      if(choice == 1 || (choice == 3 && !skillset[4]) || choice == 4 || choice == 2) {
        errorflag = false;
      }
      else cout << "Invalid choice, please try again.\n";
    } catch(invalid_argument) {
      cout << "Invalid choice, please try again.\n";
    } catch(out_of_range) {
      cout << "Invalid choice, please try again.\n";
    }
  }

  if(choice == 1) {
    if(exps >= 75) {
      a.attack = a.attack + 5;
      exps = exps-75;
      cout << "Sonic's attack was increased.\n";
    } else cout << "You do not have enough exp to purchase this.\n";
  }
  if(choice == 3) {
    if(!skillset[0]) {
      if(exps >= 100) {
        cout << "You can now perform Homing Attack.\n" << endl;
        exps = exps - 100;
        skillset[0] = true;
      } else cout << "You do not have enough exp to purchase this.\n" << endl;
    } else if(!skillset[1]) {
      if(exps >= 150) {
        cout << "You can now perform Spin Dash.\n" << endl;
        exps = exps - 150;
        skillset[1] = true;
      } else cout << "You do not have enough exp to purchase this.\n" << endl;
    } else if(!skillset[2]) {
      if(exps >= 200) {
        cout << "You can now perform Light Speed Attack.\n" << endl;
        exps = exps - 200;
        skillset[2] = true;
      } else cout << "You do not have enough exp to purchase this.\n" << endl;
    } else if(!skillset[3]) {
      if(exps >= 250) {
        cout << "You can now perform Sonic Wind.\n" << endl;
        exps = exps - 250;
        skillset[3] = true;
      } else cout << "You do not have enough exp to purchase this.\n" << endl;
    } else if(!skillset[4]) {
      if(exps >= 300) {
        cout << "You can now perform Cyloop.\n" << endl;
        exps = exps - 300;
        skillset[4] = true;
      } else cout << "You do not have enough exp to purchase this.\n" << endl;
    }
  } else if(choice == 2) {
    if(exps >= 100) {
      cout << "Sonic's max HP was increased by 10.";
      exps-=100;
      a.currentHP+=10;
      a.maxHP+=10;
    } else cout << "You do not have enough exp to purchase this.\n" << endl;
  }
}

void calcexp(int tc, int base, vector<Chao> &chaoset) {
  //20 turns for emerald, beat turn in 1 - 2 turns, 2.0x exp, 3 - 4 turns, 1.9x, etc. Stays at 1.0x if you dont finish the battle before a chaos emerald.
  double chaomult = 1;
  if(chaoset.size() > 0) {
    if(chaoset[0].chaobuffs[4]) chaomult = 1.25;
  }
  
  if(tc == 1 || tc == 2) exps+= round(2*base*chaomult);
  else if(tc == 3 || tc == 4) exps+= round(1.9*base*chaomult);
  else if(tc == 5 || tc == 6) exps+= round(1.8*base*chaomult);
  else if(tc == 7 || tc == 8) exps+= round(1.7*base*chaomult);
  else if(tc == 9 || tc == 10) exps+= round(1.6*base*chaomult);
  else if(tc == 11 || tc == 12) exps+= round(1.5*base*chaomult);
  else if(tc == 13 || tc == 14) exps+= round(1.4*base*chaomult);
  else if(tc == 15 || tc == 16) exps+= round(1.3*base*chaomult);
  else if(tc == 17 || tc == 18) exps+= round(1.2*base*chaomult);
  else if(tc == 19 || tc == 20) exps+= round(1.1*base*chaomult);
  else exps+= base;
}
