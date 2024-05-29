
#include "global.h"

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void health_gain(Character *character){
    printf("There was a health potion inside the barrel! health maxed\n");
    character->stats.hp++;
}
void health_loss(Character *character){
    printf("ACK! POISONED! health loss\n");
    character->health*= 0.9; //will this cast it to a double?
}

void health_loss_saloon(Character *character){
    printf("DAMN, you got in a nasty fight! Your wounds look bad.  health loss\n");
    character->stats.hp--;
}

void attack_gain(Character *character){
    printf("NEW GUN! attack boost!\n");
    character->active_modifiers.tempatk *= 2;
}

void attack_gain_turtle(Character *character){
    printf("Turtle: Huh? You again. I told you already, go kill that darn Bull and you'll get your information. You know what! You should kill him with this bad boy, sure he'll recognize it! recieved REMINGTON, attack boost\n");
    character->stats.atk += 2;
}

void attack_loss_booze(Character *character){
    printf("You're now drunk as hell! attack loss\n");
    character->stats.atk--;
}

void defense_gain_clothes(Character *character){
    printf("Lookin' good! defense boost\n");
    character->stats.def++;
}

void defense_loss_well(Character *character){
    printf("As you were throwing the coin, a naked man came out of the well and stole your hat! defense loss\n");
    character->stats.def--;
}

void luck_gain_ciggarette(Character *character){
    printf("Smoke feels good in your lungs, today is gonna' be a good one. luck boost!\n");
    character->stats.luc++;
}

void luck_gain_lizard(Character *character){
    printf("Looks like they're a lizard family celebrating a wedding! You play with them and you like them, they even bless you! attack and defense boost!\n");
    character->stats.atk += 2;
    character->stats.def += 2;

}

void luck_loss(Character *character){
    printf("BROKE A MIRROR!! luck loss!\n");
    character->active_modifiers.templuc *= 0.5;
}

void lizard_girls(Character *character){
    printf("You start flirting with them, but seem they were the brides of a lizard wedding, they spit and curse you!\n");
    character->stats.luc -= 3;
}

void black_jack(Character *character){
    printf("You gabled too hard and the crupier is menacing to hang you on a post, run or give something of value! you have given all of you bullets!\n");
    character->stats.bp -= 2;
}

void diamond_father(Character *character){
    printf("You approach a tall man:\n"
    "%s: Whats happening?\n"
    "???: I CAN FEEL THE JACKPOT FALLING\n"
    "%s: Who are you?\n"
    "Papadiamantis: I'm Papadiamantis\n"
    "%s: Whoa, shouldnt's you be correcting our projects?\n"
    "Papadiamantis: Later, later, I CAN SEE THE 7 LINING UP\n"
    "You walk away feeling luckier, thanks Papadiamantis\n", character->name, character->name, character->name);
    character->stats.luc += 2;
}

void bucket_spit(Character *character){
    printf("Looks like that was the frog's jacuzzi, they beat you up with their froggy legs! Health loss\n");
    character->stats.hp--;
}

void boring_coffin(Character *character){
    printf("WHAT WERE YOU THINKING OF CREEP! You've gained 'Nothing', congratulations :)\n");
}

void watch_luck_loss(Character *character){
    printf("A lost soul comes out of the watch and will follow you and ensure bad luck. Luck loss :(\n");
    character->stats.luc--;
}

void amazing_ceiling(Character *character){
    printf("You look at the ceiling. What did you expect? It is a ceiling\n");
}

void grab_horns(Character *character){
    printf("You grab the horns. You forgot that they're attached to the sheriff... Uhhh embarassing. Dignity lost\n");
}

void weapon_clean(Character *character){
    printf("You clean your weapon, augments bullets and attack\n");
    character->stats.bp++;
    character->stats.atk++;
}

void nothing(){
    printf("You found nothing\n");
}

void print_description1(Character *character){
    printf("The story begins with our protagonist, %s, waking up in his house to the sound of a noise coming from outside.\n", character->name);
    delay(1);
    printf("He jumps out of bed and rushes to the door, alarmed.\n\n");
    delay(1);
    printf("%s: (muttering) What the heck is going on?\n\n", character->name);
    delay(1);
    printf("%s opens the door and runs outside. In the desert, he sees the fish's henchman cockroaches fleeing in a hurry.\n\n", character->name);
    delay(1);
    printf("%s: (surprised) Those cockroaches! They're the fish's henchmen! \n\n", character->name);
    delay(1);
    printf("The cockroaches run faster, but one of them, the hatless and weaker one, stops, blocking %s's path.\n\n", character->name);
    delay(1);
    printf("Bandit Cockroach: Well, well, look who we have here. The famous %s, searching for his lost water, huh? FISHY told me you'd be coming. Too bad you won't get far. \n\n", character->name);
    delay(1);
    printf("%s: Let me tell you something, stinky cockroach. Nobody, and I mean nobody, steals from me and gets away with it\n\n", character->name);
    delay(1);
    printf("Bandit Cockroach: Ha! your adventure ends right here in this desert.");
}
void print_description2(Character *character){
    printf("%s enters the town, his eyes scanning the surroundings as he takes in the unfamiliar sights and sounds.\n\n", character->name);
    delay(1);
    printf("%s: (thinking to himself) Alright, %s, time to gather some intel. I need to find out where that slippery fish is hiding.\n", character->name, character->name);
    delay(1);
    printf("Looks like I'll need more information if I'm going to track down that slippery fish. Lucky for me, there are a couple of places around here where we might find some leads. \n\n");
    delay(1);
    printf("He gestures towards two buildings on either side of the street. On the left there is a funeral home and on the right a police station. \n\n");
    delay(1);
    printf("%s: Now, where should I start? The funeral home might have some... unconventional sources of information, while the police station could have more... official records. Decisions, decisions.", character->name);
}
void print_description3(Character *character){
    printf("%s approaches the coffin shop, a somber wooden structure with faded paint and a weathered sign. The door creaks open as he steps inside.\n", character->name);
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(noting the atmosphere) \"This place gives off a different vibe...\"\n");
    delay(1);
    printf("He proceeds cautiously into the dimly lit interior.\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(to himself) \"Shelly must be around here somewhere...\"\n");
    delay(1);
    printf("%s heads towards the main office, ready to confront the mafia turtle and get the information he needs.\n\n", character->name);
    delay(1);
    printf("At the Funeral Home:\n");
    delay(1);
    printf("%s approaches the door of the main office, a solid wooden door with a brass plaque that reads \"Shelly - Manager.\" He takes a deep breath before knocking.\n", character->name);
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(firmly) \"Shelly, we need to talk.\"\n");
    delay(1);
    printf("The door creaks open, revealing a dimly lit room filled with shelves of urns and other funeral paraphernalia. Shelly, a large turtle with a cigar in her mouth, sits behind a cluttered desk.\n");
    delay(1);
    printf("Shelly:\n");
    delay(1);
    printf("(gruffly) \"Well, well, well, what do we have here? Another lost soul looking for answers?\"\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(determined) \"I'm not lost, Shelly. I'm here for information. About the carapez.\"\n");
    delay(1);
    printf("Shelly's eyes narrow as she considers %s's request.\n", character->name);
    delay(1);
    printf("Shelly:\n");
    delay(1);
    printf("(shrewdly) \"Information isn't free, sweetheart. What's in it for me?\"\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(thoughtfully) \"I have something that might interest you. My will.\"\n");
    delay(1);
    printf("Shelly ponders for a moment before nodding slowly.\n");
    delay(1);
    printf("Shelly:\n");
    delay(1);
    printf("(finally) \"Alright. Knowing this, Mr. Scaled, the only way to get the information is for a big guy with two horns to speak through his mouth. You'll have to get past him to know Fishy's whereabouts, and that's enough for me.\"");          
}
void print_description4(Character *character){
    printf("At the Sheriff's Station:\n");
    delay(1);
    printf("%s approaches the sheriff's station, a sturdy-looking building with the sheriff's emblem hung over the main door. The wood creaks under his feet as he steps inside.\n", character->name);
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(surveying the interior cautiously) \"This is where I'm supposed to find Sheriff Bull...\"\n");
    delay(1);
    printf("He walks down the main hallway, passing by empty jail cells and a cluttered reception desk.\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(muttering to himself) \"The bull must be around here somewhere...\"\n");
    delay(1);
    printf("He stops in front of a closed door with a sign that reads \"Sheriff's Office.\"\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(determined) \"This is where I'll find him.\"\n");
    delay(1);
    printf("He opens the door and steps into the sheriff's office, ready to confront the bull and get the information he needs.\n\n");
    delay(1);
    printf("Toro, Chief of Police:\n");
    delay(1);
    printf("The Toro, with his imposing figure, greets you at the police station, his gaze firm and authoritative.\n");
    delay(1);
    printf("\"So, you're the one they sent to take me down. You must be more foolish than you look.\"\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("Stands firm in front of the Toro, his determination palpable.\n");
    delay(1);
    printf("\"I'm not here for pleasantries. I'm here to find FISHY and stop any obstacle in my way, even if it includes the law.\"\n");
    delay(1);
    printf("Toro, Chief of Police:\n");
    delay(1);
    printf("He looks at you with disdain, preparing for the showdown.\n");
    delay(1);
    printf("\"Ha! You're in way over your head, cowboy. Prepare to face the full force of the law!\"");  
}
void print_description5(Character *character){
    printf("%s enters the sheriff's station, the door squeaking as it opens. The interior is illuminated by fluorescent lights, and there are several agents busy at their desks.\n\n", character->name);
    delay(1);
    printf("%s: (murmuring) Let's see what we can find here. \n\n", character->name);
    delay(1);
    printf("He approaches the counter where the sheriff is, an imposing bull wearing a cowboy hat. \n\n");
    delay(1);
    printf("Sheriff Bull: (looking up) Good afternoon, how can I help you? \n\n");
    delay(1);
    printf("%s: (determined) Hello, sheriff. I'm looking for information about a fish that's been causing trouble in the area. Have you heard anything about it?\n\n", character->name);
    delay(1);
    printf("Sheriff Bull: (frowning) Hmm, that darn Fishy... Yes, we've had some reports about him. But he moves in the shadows, it won't be easy to get that information. \n\n");
    delay(1);
    printf("%s: (nodding) I see. How do I get it then? \n\n", character->name);
    delay(1);
    printf("Sheriff Bull: In this town, evil has a single headquarters and hides under a single shell. Defeat the queen of the dead, Shelly the turtle, and you'll get what you crave so much.\n\n");
    delay(1);
    printf("%s: (frowning) The funeral home? There's no time to waste, let's see what that shell with legs has for me. \n\n", character->name);
    delay(1);
    printf("%s thanks the sheriff and heads towards the back alley, ready to confront the turtle and get the information he needs.", character->name);
}
void print_description6(Character *character){
    printf("%s arrives at the funeral home, a gloomy wooden structure with a rusty sign creaking in the wind. The door opens with an ominous squeak as %s steps inside.\n\n", character->name, character->name);
    delay(1);
    printf("%s: (surveying the interior cautiously) This place gives me the creeps...\n\n", character->name);
    delay(1);
    printf("He walks down the main hallway, passing rows of empty chairs and framed photos of the deceased on the walls. \n\n");
    delay(1);
    printf("%s: (muttering to himself) Alright, Shelly must be around here somewhere... \n\n", character->name);
    delay(1);
    printf("He stops in front of a closed door with a sign that reads Main Office.\n\n");
    delay(1);
    printf("%s: (determined) This is where I'll find Shelly. \n\n", character->name);
    delay(1);
    printf("%s opens the door and steps into the main office, ready to confront the mafia turtle and get the information he needs. \n\n", character->name);
    delay(1);
    printf("The mafia turtle greets you in her funeral parlor, a defiant look in her eyes as she prepares for the showdown.\n\n");
    delay(1);
    printf("Shelly: Well, well, well... What do we have here? The Toro's pawn come to do his dirty work? \n\n");
    delay(1);
    printf("%s: He takes a combat stance, his gaze determined as he prepares for battle. I'm not here for chit-chat. Toro wants me to stop you, and I'm not going to let you stand in my way. \n\n", character->name);
    delay(1);
    printf("Tortuga Mafiosa: Oh, how brave! But Toro doesn't know who he's messing with. Get ready to face the true might of this city's mafia.");   
}
void print_description7(Character *character){
    printf("%s approaches the casino, an ostentatious building with flashing neon lights and lively music resonating from within. The entrance is guarded by two burly gorillas.\n", character->name);
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(surveying the scene) \"This looks like a lively place...\"\n");
    delay(1);
    printf("He strides purposefully towards the casino entrance.\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(addressing the gorillas) \"Allow me to pass, I have important matters to attend to inside.\"\n");
    delay(1);
    printf("The gorillas regard him with seriousness, evaluating him.\n");
    delay(1);
    printf("Gorilla 1:\n");
    delay(1);
    printf("(furrowing his brow) \"I'm sorry, buddy. We can't just let anyone in.\"\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(insistent) \"I'm not just anyone. I just need a few minutes with the boss of this place.\"\n");
    delay(1);
    printf("The gorillas exchange glances before reluctantly allowing him entry, albeit with some reluctance.\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(grateful) \"Thank you, I won't disappoint.\"\n");
    delay(1);
    printf("%s steps through the casino entrance, ready to confront the fish and resolve his quest once and for all.", character->name);
}
void print_description8(Character *character){
    printf("%s approaches the casino, an ostentatious building with flashing neon lights and lively music resonating from within. The entrance is guarded by two burly gorillas.\n", character->name);
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(surveying the scene) \"This looks like a lively place...\"\n");
    delay(1);
    printf("He strides purposefully towards the casino entrance.\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(addressing the gorillas) \"Allow me to pass, I have important matters to attend to inside.\"\n");
    delay(1);
    printf("The gorillas regard him with seriousness, evaluating him.\n");
    delay(1);
    printf("Gorilla 1:\n");
    delay(1);
    printf("(furrowing his brow) \"I'm sorry, buddy. We can't just let anyone in.\"\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(insistent) \"I'm not just anyone. I just need a few minutes with the boss of this place.\"\n");
    delay(1);
    printf("The gorillas exchange glances before reluctantly allowing him entry, albeit with some reluctance.\n");
    delay(1);
    printf("%s:\n", character->name);
    delay(1);
    printf("(grateful) \"Thank you, I won't disappoint.\"\n");
    delay(1);
    printf("%s steps through the casino entrance, ready to confront the fish and resolve his quest once and for all.", character->name);
}
void print_description9(Character *character){
    printf("You slowly open the doors of the VIP room...\n");
    delay(1);
    printf("FISHY is in the center of the VIP room, nervously swimming in his fishbowl.\n");
    delay(1);
    printf("Fishy O'Sullivan: Ah, %s. You've finally arrived. I thought my henchmen would stop you.", character->name);
    delay(1);
    printf("%s faces Fishy with determination, his gaze cold and filled with anger.\n", character->name);
    delay(1);
    printf("%s: It's over, Fishy. You stole my water and hid behind your henchmen like a coward. It's time to pay for what you've done!\n", character->name);
    delay(1);
    printf("Fishy tries to remain calm, though his voice trembles slightly.\n");
    delay(1);
    printf("Fishy O'Sullivan: You don't understand, cowboy. But it seems I have no choice but to face you.\n");
    delay(1);
    printf("%s takes a step forward, determined.\n", character->name);
    delay(1);
    printf("%s: Prepare to face the consequences of your actions!\n", character->name);
}

void print_description10(Character *character){
    printf("Turtle's body lays on the ground, cold as ice\n");
}

void print_description11(Character *character){
    printf("You can hear the paperwork being done, its tense in here\n");
}

void print_description12(Character *character){
    printf("You shouldn't be here, you just murdered this man\n");
}

void print_description13(Character *character){
    printf("The shop smells horrible...\n");
}

void print_description14(Character *character){
    printf("The town looks peaceful. Just an old man looking at you from his porch\n");
}

void print_description15(Character *character){
    printf("Just a dry wasteland\n");
}

// you need to copy paste everything in here
// you need to change the scenario list so that it has the names of all the pointers. 