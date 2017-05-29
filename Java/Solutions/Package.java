import java.io.*;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class Package{

	double limit;
	ArrayList<Item> items;
	ArrayList<ArrayList<Item>> combinations;
	
	public ArrayList<ArrayList<Item>> createCombinations(){

		for(int x = 0; x < items.size(); x++){
			Item currentItem = items.get(x);
			int combinationSize = combinations.size();
			for(int y = 0; y < combinationSize; y++){
				ArrayList<Item> combination = combinations.get(y);
				ArrayList<Item> newCombination = new ArrayList<Item>(combination);
				newCombination.add(currentItem);
				combinations.add(newCombination);
			}
			ArrayList<Item> current = new ArrayList<Item>();
			current.add(currentItem);
			combinations.add(current);
		}
		return combinations;
	}
		public Package(double l, ArrayList<Item> i){
		limit = l;
		items = i;
		combinations = new ArrayList<ArrayList<Item>>();
	}
	
	public void filterItems(){
		Iterator<Item> iter = items.iterator();
		while(iter.hasNext()){
			Item i = iter.next();
			if(i.weight > limit)
				iter.remove();
		}
	}
	public double getWeight(ArrayList<Item> items){
		double total = 0;
		for(Item i : items){
			total += i.weight;
		}
		return total;
	}
	
	public double getPrice(ArrayList<Item> items){
		double total = 0;
		for(Item i : items){
			total += i.price;
		}
		return total;
	}
	
	public ArrayList<Item> getBestPackage(){
		ArrayList<Item> bestCombination = new ArrayList<Item>();
		double bestCost = 0;
		double bestWeight = 100; //Max limit given in problem
		for(ArrayList<Item> combination : combinations){
			double combinationWeight = getWeight(combination);
			if(combinationWeight > limit){
				continue;
			}else{
				double combinationPrice = getPrice(combination);
				if(combinationPrice > bestCost){
					bestCost = combinationPrice;
					bestCombination = combination;
					bestWeight = combinationWeight;
				}else if(combinationPrice == bestCost){
					if(combinationWeight < bestWeight){
						bestCost = combinationPrice;
						bestCombination = combination;
						bestWeight = combinationWeight;
					}
				}
			}
		}
		return bestCombination;
	}
	
	public void findPackage(){
		filterItems();
		combinations = createCombinations();
		if(combinations.size() == 0){
			System.out.println("-");
		}else{
			ArrayList<Item> bestCombination = getBestPackage();
			Collections.sort(bestCombination);
			printOutput(bestCombination);
		}
	}
	
	public void printOutput(ArrayList<Item> items){
		StringBuilder sb = new StringBuilder();
		boolean isFirst = true;
		for (Item i : items) {
			if(isFirst){
				sb.append(i.id);
				isFirst = false;
			}else{
				sb.append("," + i.id);
			}
		}
		System.out.println(sb);
	}
	
	public static void main(String[] args){
		File file = new File("input.txt");
		try{
			BufferedReader in = new BufferedReader(new FileReader(file));
			String line;
			while((line = in.readLine()) != null){
				if(line.length() == 0)
					continue;
				String[] lineArray = line.split(":");
				double weightLimit = Integer.parseInt(lineArray[0].trim());				
				String[] stringItems = lineArray[1].trim().split(" ");
				ArrayList<Item> inputs = new ArrayList<Item>();
				for(String stringItem : stringItems){
					String[] itemDetails = stringItem.split(",");
					int id = Integer.parseInt(itemDetails[0].substring(1));
					double weight = Double.parseDouble(itemDetails[1]);
					double price = Double.parseDouble(itemDetails[2].substring(1, itemDetails[2].length()-1));
					Item item = new Item(id, weight, price);
					inputs.add(item);
				}
				Package p = new Package(weightLimit, inputs);
				p.findPackage();
			}
		}catch(IOException e){
			System.out.println(e);
		}
	}
	
	public static class Item implements Comparable<Item>{
		int id;
		double weight, price;
		public Item(int id, double weight, double price){
			this.id = id;
			this.weight = weight;
			this.price = price;
		}
		
		public String toString(){
			return "(" + id + "," + weight + "," + price + ")";
		}
		
		public int compareTo(Item i){
			return this.id - i.id;
		}
	}
}