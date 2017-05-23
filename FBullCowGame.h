//This header file declares what private and public variables my 'type functions' require.

#pragma once
#include <string>


using FString = std::string;  
using Ftext = std::string;
using int32 = int;			//makes it Unreal friendly

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_length,
	Not_lower_case
};

class FBullCowGame 
{
public:
	FBullCowGame(); // constructor

	//These are called signatures

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	FString GetHiddenWord() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); 

	FBullCowCount SubmitValidGuess(FString);

	//These are my wordlists
	FString ThreeLetterWordList[157]{ "act", "age", "ago", "aid", "aim", "air", "and", "any", "arm", "art", "ask", "bad", "bag", "ban", "bar", "bed", "bet", "big", "bit", "box", "boy", "bus", "but", "buy", "can", "cap", "car", "cat", "cop", "cow", "cry", "cup", "cut", "day", "die", "dig", "dog", "dry", "due", "ear", "eat", "end", "era", "etc", "fan", "far", "fat", "few", "fit", "fix", "fly", "for", "fun", "gap", "gas", "gay", "get", "gun", "guy", "hat", "her", "hey", "him", "hip", "his", "hit", "hot", "how", "ice", "its", "jet", "jew", "job", "joy", "key", "kid", "lab", "lap", "law", "lay", "leg", "let", "lie", "lip", "lot", "low", "mad", "man", "map", "may", "mix", "mrs", "net", "new", "nod", "nor", "not", "now", "nut", "oil", "old", "one", "our", "out", "owe", "own", "pan", "pay", "per", "pet", "pie", "pot", "put", "raw", "red", "rid", "row", "rub", "run", "sad", "say", "sea", "set", "sex", "she", "sin", "sir", "sit", "six", "ski", "sky", "son", "sue", "sun", "tap", "tax", "tea", "ten", "the", "tie", "tip", "toe", "top", "toy", "try", "two", "use", "via", "war", "way", "wet", "who", "why", "win", "yes", "yet", "you" };
	FString FourLetterWordList[402]{ "able", "acid", "aide", "aids", "also", "army", "auto", "back", "bake", "band", "bank", "base", "bean", "bear", "beat", "belt", "bend", "best", "bike", "bind", "bird", "bite", "blow", "blue", "boat", "body", "bond", "bone", "born", "both", "bowl", "buck", "burn", "bury", "busy", "cake", "camp", "card", "care", "case", "cash", "cast", "chef", "chip", "cite", "city", "club", "clue", "coal", "coat", "code", "cold", "come", "cope", "copy", "core", "corn", "cost", "crew", "crop", "dare", "dark", "date", "deal", "dear", "debt", "deck", "deny", "desk", "diet", "dirt", "dish", "down", "drag", "draw", "drop", "drug", "dust", "duty", "each", "earn", "east", "easy", "face", "fact", "fade", "fail", "fair", "farm", "fast", "fate", "fear", "file", "film", "find", "fine", "fire", "firm", "fish", "five", "flag", "flat", "flow", "folk", "form", "four", "from", "fuel", "fund", "gain", "game", "gate", "gaze", "gear", "gift", "girl", "give", "glad", "goal", "gold", "golf", "grab", "grey", "grow", "hair", "half", "hand", "hang", "hard", "hate", "have", "head", "hear", "heat", "help", "hero", "hide", "hire", "hold", "hole", "holy", "home", "hope", "host", "hour", "huge", "hurt", "idea", "into", "iron", "item", "jail", "join", "joke", "jump", "jury", "just", "kind", "king", "know", "lack", "lady", "lake", "land", "last", "late", "lawn", "lead", "leaf", "lean", "left", "life", "lift", "like", "line", "link", "list", "live", "load", "loan", "lock", "long", "lose", "lost", "lots", "loud", "love", "luck", "lung", "mail", "main", "make", "male", "many", "mark", "mask", "math", "meal", "mean", "meat", "menu", "milk", "mind", "mine", "mode", "more", "most", "move", "much", "must", "myth", "name", "near", "neck", "news", "next", "nice", "nose", "note", "okay", "once", "only", "open", "oven", "over", "pace", "pack", "page", "pain", "pair", "pale", "palm", "pant", "park", "part", "past", "path", "peak", "pick", "pile", "pine", "pink", "plan", "play", "plot", "plus", "poem", "poet", "pole", "port", "pose", "post", "pour", "pray", "pure", "push", "quit", "race", "rail", "rain", "rank", "rate", "read", "real", "rely", "rest", "rice", "rich", "ride", "ring", "rise", "risk", "road", "rock", "role", "rope", "rose", "rule", "rush", "safe", "sake", "sale", "salt", "same", "sand", "save", "seat", "self", "send", "ship", "shit", "shoe", "shop", "shot", "show", "shut", "sick", "side", "sigh", "sign", "sing", "sink", "site", "size", "skin", "slip", "slow", "snap", "snow", "soft", "soil", "some", "song", "sort", "soul", "soup", "spin", "spot", "star", "stay", "step", "stir", "stop", "such", "suit", "sure", "swim", "tail", "take", "tale", "talk", "tank", "tape", "task", "team", "tear", "tend", "term", "than", "them", "then", "they", "thin", "this", "thus", "time", "tiny", "tire", "tone", "tour", "town", "trip", "true", "tube", "turn", "twin", "type", "ugly", "unit", "upon", "urge", "used", "user", "vary", "vast", "very", "view", "vote", "wage", "wait", "wake", "walk", "want", "warm", "warn", "wash", "wave", "weak", "wear", "west", "what", "when", "whom", "wide", "wife", "wild", "wind", "wine", "wing", "wipe", "wire", "wise", "wish", "with", "word", "work", "wrap", "yard", "yeah", "year", "your", "zone" };
	FString FiveLetterWordList[348]{ "about", "above", "abuse", "actor", "admit", "adopt", "adult", "after", "agent", "album", "alive", "alone", "along", "alter", "among", "anger", "angle", "angry", "argue", "arise", "armed", "aside", "avoid", "awful", "badly", "basic", "beach", "begin", "being", "below", "bench", "birth", "black", "blade", "blame", "blind", "block", "board", "brain", "brand", "bread", "break", "brick", "brief", "bring", "broad", "brown", "brush", "build", "bunch", "buyer", "cabin", "cable", "cause", "chain", "chair", "chart", "chase", "cheap", "chest", "chief", "child", "claim", "clean", "clear", "climb", "close", "cloud", "coast", "could", "count", "court", "cover", "craft", "crash", "crazy", "cream", "crime", "crowd", "daily", "dance", "death", "delay", "depth", "dirty", "doubt", "dozen", "draft", "dream", "drink", "drive", "early", "earth", "eight", "empty", "enjoy", "entry", "equal", "exact", "exist", "extra", "faith", "false", "fault", "field", "fight", "final", "first", "flame", "flesh", "float", "focus", "force", "forth", "found", "frame", "fresh", "front", "fruit", "ghost", "giant", "given", "glove", "grade", "grain", "grand", "grant", "grave", "great", "group", "guard", "guest", "guide", "habit", "heart", "heavy", "honey", "horse", "hotel", "house", "human", "ideal", "image", "imply", "index", "joint", "judge", "juice", "knife", "large", "later", "laugh", "layer", "learn", "least", "lemon", "light", "lover", "lower", "lucky", "lunch", "major", "maker", "match", "maybe", "mayor", "media", "metal", "might", "minor", "model", "money", "month", "moral", "mount", "mouse", "mouth", "movie", "music", "naked", "newly", "night", "noise", "north", "novel", "nurse", "ocean", "often", "other", "ought", "owner", "paint", "panel", "party", "patch", "pause", "phase", "phone", "piano", "pilot", "pitch", "place", "plane", "plant", "plate", "point", "porch", "pound", "power", "price", "pride", "prime", "print", "proud", "prove", "quick", "quiet", "quite", "quote", "radio", "raise", "range", "rapid", "ratio", "reach", "react", "ready", "relax", "reply", "rifle", "right", "rough", "round", "route", "sauce", "scale", "scope", "score", "shade", "shake", "shape", "share", "sharp", "shelf", "shift", "shine", "shirt", "shock", "shore", "short", "shout", "shrug", "sight", "since", "slave", "slice", "slide", "smart", "smile", "smoke", "solar", "solid", "solve", "sound", "south", "space", "speak", "spend", "split", "sport", "stage", "stair", "stake", "stand", "stare", "steal", "stick", "stock", "stone", "store", "storm", "story", "strip", "study", "style", "sugar", "super", "swear", "swing", "table", "teach", "terms", "thank", "their", "thick", "thing", "think", "third", "those", "throw", "tired", "today", "topic", "touch", "tough", "tower", "trace", "track", "trade", "trail", "train", "trend", "trial", "tribe", "trick", "truck", "truly", "twice", "uncle", "under", "until", "urban", "value", "video", "virus", "vital", "voice", "voter", "waste", "watch", "water", "weigh", "while", "white", "whole", "whose", "woman", "works", "world", "worth", "would", "wound", "write", "wrong", "yield", "young", "yours", "youth" };
	FString SixLetterWordList[216]{ "action", "active", "adjust", "admire", "advice", "advise", "agency", "almost", "amount", "answer", "around", "aspect", "author", "barely", "basket", "beauty", "behind", "belong", "beyond", "bother", "branch", "breast", "breath", "bridge", "bright", "broken", "budget", "burden", "campus", "carbon", "change", "charge", "client", "closer", "column", "comedy", "county", "couple", "course", "cousin", "credit", "custom", "danger", "depict", "deputy", "design", "detail", "direct", "double", "during", "easily", "editor", "employ", "enough", "ethics", "ethnic", "expand", "fabric", "factor", "fairly", "family", "famous", "father", "figure", "finger", "flavour", "flight", "flower", "forest", "forget", "formal", "fourth", "friend", "garden", "garlic", "gather", "gently", "gifted", "glance", "golden", "ground", "growth", "guilty", "handle", "hardly", "honest", "hungry", "hunter", "ignore", "impact", "impose", "income", "inform", "injury", "invest", "island", "itself", "jacket", "junior", "launch", "lawyer", "legacy", "length", "listen", "locate", "mainly", "makeup", "margin", "market", "master", "mental", "method", "minute", "modern", "modest", "mostly", "mother", "muscle", "myself", "native", "nature", "nearby", "nearly", "normal", "notice", "number", "object", "obtain", "orange", "others", "parent", "partly", "period", "permit", "person", "phrase", "planet", "player", "plenty", "pocket", "poetry", "police", "policy", "powder", "priest", "prison", "profit", "public", "rating", "reason", "region", "remain", "remind", "result", "retain", "sacred", "safety", "sample", "saving", "scared", "scream", "script", "search", "second", "sector", "senior", "sexual", "shadow", "should", "shower", "signal", "silent", "silver", "simple", "simply", "singer", "single", "slight", "social", "source", "spread", "spring", "square", "stable", "steady", "stream", "strike", "string", "stroke", "strong", "studio", "stupid", "submit", "surely", "survey", "switch", "symbol", "thanks", "theory", "tongue", "toward", "travel", "unable", "united", "unlike", "virtue", "visual", "volume", "wander", "wealth", "weapon", "weight", "widely", "winter", "wisdom", "wonder" };
	FString SevenLetterWordList[134]{ "acquire", "adviser", "another", "anxiety", "anymore", "article", "blanket", "briefly", "cabinet", "capture", "careful", "central", "century", "certain", "chamber", "chapter", "charity", "climate", "clothes", "cluster", "combine", "company", "compare", "complex", "confirm", "consume", "convert", "counter", "country", "courage", "destroy", "display", "dispute", "divorce", "drawing", "exactly", "explain", "factory", "faculty", "failure", "fashion", "fighter", "foreign", "formula", "fortune", "founder", "funeral", "handful", "hearing", "heavily", "himself", "history", "holiday", "housing", "husband", "improve", "include", "instead", "journal", "journey", "justice", "justify", "kitchen", "lawsuit", "leading", "machine", "medical", "miracle", "mistake", "mixture", "musical", "nervous", "network", "nuclear", "organic", "outside", "painful", "painter", "parking", "payment", "penalty", "picture", "plastic", "poverty", "predict", "privacy", "private", "problem", "produce", "product", "profile", "project", "promise", "protein", "provide", "publish", "qualify", "quality", "quickly", "quietly", "rapidly", "reading", "reality", "respond", "roughly", "routine", "scholar", "section", "senator", "shortly", "society", "soldier", "special", "stomach", "storage", "strange", "subject", "surface", "therapy", "towards", "tragedy", "trouble", "typical", "undergo", "uniform", "variety", "various", "version", "victory", "violate", "violent", "wealthy", "whisper", "working" };
	FString EightLetterWordList[54]{ "absolute", "argument", "behaviour", "birthday", "boundary", "category", "champion", "clothing", "complain", "computer", "consider", "consumer", "creation", "customer", "daughter", "dialogue", "directly", "discover", "distance", "document", "domestic", "dominate", "educator", "favourite", "friendly", "hospital", "industry", "investor", "judgment", "majority", "neighbour", "organize", "personal", "physical", "platform", "powerful", "previous", "province", "purchase", "question", "reaction", "regional", "relation", "romantic", "scenario", "security", "shoulder", "software", "somewhat", "southern", "strongly", "teaching", "thousand", "yourself" };



private:
	//see constructor for initialisation
	
	int32 MyCurrentTry;	
	FString MyHiddenWord;
	bool bIsThisGameWon;
	
	FString StartofGamePrintIntroAndReturnAHiddenWord();

	//These are called helper functions
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};
